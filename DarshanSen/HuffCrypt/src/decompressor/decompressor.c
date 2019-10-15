/*Program to decompress an input binary file by Huffman coding*/

#ifdef _WIN32
#include "..\..\includes\commons.h"
#include "..\..\includes\decompressor.h"
#else
#include "../../includes/commons.h"
#include "../../includes/decompressor.h"
#endif

//Decompressor
void decompressor(char *in, char *out){
	//This converts an input binary file into a decompressed text file

	/*Analyzing input*/
	//Opens compressed file
	FILE *cfile = fopen(in, "rb");
	if(cfile == NULL){
		//Handles error due to missing input file
		printf("\nError: \"%s\" not found.\n", in);
		printf("\nProgram terminated.\n");
		exit(1);
	}
	//Reads num_bits
	int num_bits;
	fread(&num_bits, sizeof(num_bits), 1, cfile);
	//Reads num_chars
	char num_of_characters;
	fread(&num_of_characters, sizeof(num_of_characters), 1, cfile);

	/*Making tree*/
	//Create root node of tree
	d_node *tree = (d_node *) malloc(sizeof(d_node));
	tree -> character = 0;
	tree -> LEFT = NULL;
	tree -> RIGHT = NULL;
	//Reads keys of characters
	char encoded_len, character;
	printf("\nMaking tree:\n");
	while(num_of_characters){
		fread(&character, sizeof(character), 1, cfile);
		fread(&encoded_len, sizeof(encoded_len), 1, cfile);
		d_make_tree(tree, cfile, character, encoded_len);
		--num_of_characters;
	}
	//Traverse tree
	printf("\n\nInorder:\n\"");
	d_inorder(tree);
	printf("\"\n");
	printf("\nPreorder:\n\"");
	d_preorder(tree);
	printf("\"\n");

	/*Decompression*/
	//Opens dfile
	FILE *dfile = fopen(out, "w");
	if(dfile == NULL){
		//Handles file creation errors
		printf("\nError: \"%s\" cannot be created.\n", out);
		printf("\nProgram terminated.\n");
		exit(1);
	}
	//Traverse and write
	printf("\nDecrypting data:\n");
	char ch_buf, pos_buf = 0, dir;
	d_node *ptr = tree;
	fread(&ch_buf, sizeof(ch_buf), 1, cfile);
	printf("||||||||\t");
	d_print_char(ch_buf);
	printf("\t");
	while(num_bits){
		dir = (ch_buf >> pos_buf) & 1;
		d_print_char(dir);
		printf("\t");
		++pos_buf;
		if(pos_buf == 8){
			printf("||||||||\t");
			fread(&ch_buf, sizeof(ch_buf), 1, cfile);
			d_print_char(ch_buf);
			printf("\t");
			pos_buf = 0;
		}
		if(dir == 0)
			tree = tree -> LEFT;
		else
			tree = tree -> RIGHT;
		--num_bits;
		if(tree -> character != 0){
			printf("<<<<<<<<\t");
			d_print_char(tree -> character);
			printf("\t>>>>>>>>\t");
			fputc(tree -> character, dfile);
			tree = ptr;
		}
	}

	//Clear tree
	tree = ptr;
	d_clear_tree(tree);

	//Closes dfile
	fclose(cfile);
	fclose(dfile);

	printf("\n");

	//END OF DECOMPRESSION
}