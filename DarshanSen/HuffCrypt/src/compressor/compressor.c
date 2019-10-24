/*Program to compress an input text file by Huffman coding*/

#ifdef _WIN32
#include "..\..\includes\commons.h"
#include "..\..\includes\compressor.h"
#else
#include "../../includes/commons.h"
#include "../../includes/compressor.h"
#endif

//Compressor
void compressor(char *in, char *out){
	//This converts an input text file into a compressed binary file

	/*Analyzing input*/
	//Opening input file
	char FLAG = 0;
	/*
	FLAG is 0 when input file contains all ASCII characters.
	FLAG is 1 when input file contains even one non-ASCII character.
	*/
	FILE *file = fopen(in, "r");
	if(file == NULL){
		//Handles error due to missing input file
		printf("\nError: \"%s\" not found.\n", in);
		printf("\nProgram terminated.\n");
		exit(1);
	}
	//initial_frequency_arr stores frequencies of characters with ASCII from 0 to 126
	c_enc initial_frequency_arr[127] = {0};
	char ch_buf;
	while((ch_buf = fgetc(file)) != EOF){
		if(ch_buf > 126 || ch_buf < 0){
			//non-ASCII character encountered
			FLAG = 1;
			printf("\nNon-ASCII character encountered: %d\tcharacter: \'%c\'", ch_buf, ch_buf);
		}else{
			++initial_frequency_arr[ch_buf].frequency;
		}
	}
	//Prints frequencies of characters
	if(FLAG)	printf("\n");
	printf("\ninitial_frequency_arr:\n");
	char i;
	for(i = 0; i < 127; ++i)
		printf("ascii: %d\tcharacter: \'%c\'\tfrequency: %d\n", i, i, initial_frequency_arr[i].frequency);

	/*Minheap*/
	//Finding number of unique characters
	char num_of_characters = 0;
	for(i = 0; i < 127; ++i)
		if(initial_frequency_arr[i].frequency > 0)
			++num_of_characters;
	//Later used
	char num_of_characters_copy = num_of_characters;
	//Inializes arr
	c_node *arr = (c_node *) calloc(127, sizeof(c_node));
	char i_in_num_of_characters = 0;
	for(i = 0; i < 127; ++i){
		if(initial_frequency_arr[i].frequency > 0){
			arr[i_in_num_of_characters].character = i;
			arr[i_in_num_of_characters].frequency = initial_frequency_arr[i].frequency;
			arr[i_in_num_of_characters].LEFT = NULL;
			arr[i_in_num_of_characters].RIGHT = NULL;
			++i_in_num_of_characters;
		}
	}
	//Prints arr before heapify
	printf("\narr:\nindex\t\tcharacter\tfrequency\n");
	for(i = 0; i < num_of_characters; ++i)
		printf("%d\t\t\'%c\'\t\t%d\n", i, arr[i].character, arr[i].frequency);
	//Heapify
	c_heapify(arr, num_of_characters);
	//Prints arr after heapify
	printf("\nheapified arr:\nindex\t\tcharacter\tfrequency\n");
	for(i = 0; i < num_of_characters; ++i)
		printf("%d\t\t\'%c\'\t\t%d\n", i, arr[i].character, arr[i].frequency);

	/*Huffman tree*/
	//Make Huffman tree
	if(num_of_characters == 1){
		c_node *NEW = (c_node *) malloc(sizeof(c_node));
		NEW -> LEFT = arr;
		NEW -> RIGHT = NULL;
		NEW -> character = 0;
		NEW -> frequency = arr -> frequency;
		arr = NEW;
	}else{
		c_make_huffman_tree(arr, &num_of_characters);
	}
	//Prints characters in Huffman tree in preorder
	printf("\nHuffman tree(preorder)-\n\"");
	c_print_huff_preorder(arr);
	printf("\"\n");
	//Prints characters in Huffman tree in inorder
	printf("\nHuffman tree(inorder)-\n\"");
	c_print_huff_inorder(arr);
	printf("\"\n");

	/*Encoding characters*/
	c_stack *stk = (c_stack *) malloc(sizeof(c_stack));
	stk -> TOP = -1;
	printf("\nIn encoder-\n");
	c_encoder(arr, stk, initial_frequency_arr);
	//Free stack
	free(stk);
	//Clear huffman tree
	c_clear_tree(arr);
	//Prints initial_frequency_arr
	printf("\nPrints initial_frequency_arr-\n");
	for(i = 0; i <= 126; ++i){
		if(initial_frequency_arr[i].frequency){
			printf("\'%c\': ", i);
			printf("%s\n", initial_frequency_arr[i].encoded);
		}
	}

	/*Compression*/
	//Key part
	//Opens compressed file
	FILE *cfile = fopen(out, "wb");
	if(cfile == NULL){
		//Handles file creation errors
		printf("\nError: \"%s\" cannot be created.\n", out);
		printf("\nProgram terminated.\n");
		exit(1);
	}
	//Inserting number of bits used
	int num_bits = 0;
	for(i = 0; i <= 126; ++i){
		if(initial_frequency_arr[i].frequency){
			num_bits += strlen(initial_frequency_arr[i].encoded) * initial_frequency_arr[i].frequency;
		}
	}
	fwrite(&num_bits, sizeof(num_bits), 1, cfile);
	printf("\nnum_bits: %d\n", num_bits);
	//Inserting number of characters
	fwrite(&num_of_characters_copy, sizeof(num_of_characters_copy), 1, cfile);
	printf("\nnum_of_characters_copy: %d\n", num_of_characters_copy);
	//Inserting characters with keys
	char scanned, pos_buf = 0;
	ch_buf = 0;
	char encoded_len, encoded[127];
	for(i = 0; i <= 126; ++i){
		if(initial_frequency_arr[i].frequency){
			fwrite(&i, sizeof(i), 1, cfile);
			encoded_len = strlen(initial_frequency_arr[i].encoded);
			fwrite(&encoded_len, sizeof(encoded_len), 1, cfile);
			strcpy(encoded, initial_frequency_arr[i].encoded);
			char iter = 0;
			while(encoded[iter] != '\0'){
				ch_buf |= ((encoded[iter] - '0') << pos_buf);
				++pos_buf;
				if(pos_buf == 8){
					fwrite(&ch_buf, sizeof(ch_buf), 1, cfile);
					ch_buf = 0;
					pos_buf = 0;
				}
				++iter;
			}
			if(pos_buf > 0){
				fwrite(&ch_buf, sizeof(ch_buf), 1, cfile);
				ch_buf = 0;
				pos_buf = 0;
			}
		}
	}

	//Compression part
	//Move file pointer to beginning
	fseek(file, 0, SEEK_SET);
	//Initializing variables
	scanned, pos_buf = 0;
	ch_buf = 0;
	//Traverse and compress
	printf("\nCompressed data:\n");
	while((scanned = fgetc(file)) != EOF){
		if(scanned >= 0 && scanned <= 126){
			strcpy(encoded, initial_frequency_arr[scanned].encoded);
			if(pos_buf == 8){
				c_print_char(ch_buf);
				fwrite(&ch_buf, sizeof(ch_buf), 1, cfile);
				ch_buf = 0;
				pos_buf = 0;
			}
			i = 0;
			while(encoded[i] != '\0'){
				ch_buf |= ((encoded[i] - '0') << pos_buf);
				++pos_buf;
				if(pos_buf == 8){
					c_print_char(ch_buf);
					fwrite(&ch_buf, sizeof(ch_buf), 1, cfile);
					ch_buf = 0;
					pos_buf = 0;
				}
				++i;
			}
		}

	}
	//Clearing residual characters
	if(pos_buf > 0){
		c_print_char(ch_buf);
		fwrite(&ch_buf, sizeof(ch_buf), 1, cfile);
		ch_buf = 0;
		pos_buf = 0;
	}
	printf("\n");

	//Closing files
	fclose(file);
	fclose(cfile);

	/*Warning message if input file
	contains non-ASCII characters*/
	if(FLAG){
		printf("\nWarning: \"%s\" contains non-ASCII characters,\n\twhich have been ignored while compressing contents into \"%s\".\n", in, out);
	}

	//END OF COMPRESSION
}