/*Program to compress/decompress files via Huffman encryption/decryption technique*/

#ifdef _WIN32
#include "..\includes\commons.h"
#include "..\includes\compressor.h"
#include "..\includes\decompressor.h"
#else
#include "../includes/commons.h"
#include "../includes/compressor.h"
#include "../includes/decompressor.h"
#endif

void error(void);

void error(void){
	printf("\nError: Illegal entry\n");
	printf("\nUsage: HuffCrypt [-c | -d] [input file] [output file]\n");
	printf("\n\t-c\tCompressor mode. This mode is used for compressing\n\t\tan input file with only ASCII characters into a binary file.\n");
	printf("\n\t-c\tDecompressor mode. This mode is used for decompressing\n\t\ta prior compressed input binary file into the original file.\n");
	printf("\nProgram terminated.\n");
	exit(1);
}

int main(int argc, char *argv[]){
	if(argc != 4){
		//Handles error due to invalid entry 
		error();
	}

	printf("\n***START OF PROGRAM***\n");

	switch(argv[1][1]){
		case 'c':
			//Compressor mode
			compressor(argv[2], argv[3]);
			break;
		case 'd':
			//Decompressor mode
			decompressor(argv[2], argv[3]);
			break;
		default:
			error();
	}

	printf("\n***END OF PROGRAM***\n");

	//END OF PROGRAM
	return 0;
}