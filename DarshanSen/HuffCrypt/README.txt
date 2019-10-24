APPLICATION TITLE: HuffCrypt

PURPOSE OF APPLICATION: This application demonstrates the compression/decompression of files with
			strictly ASCII characters via Huffman encryption/decompression technique.

DATE: 20/12/2018

HOW TO START THIS APPLICATION:

	For Windows:	gcc -std=c99 -Ofast .\src\compressor\* .\src\decompressor\* .\src\huffcrypt.c -o HuffCrypt

	For the rest:	gcc -std=c99 -Ofast ./src/compressor/* ./src/decompressor/* ./src/huffcrypt.c -o HuffCrypt

	Also, add to PATH in environment variables.

AUTHOR: Darshan Sen

USAGE:

HuffCrypt [-c | -d] [input file] [output file]

	-c	Compressor mode. This mode is used for compressing
		an input file with only ASCII characters into a binary file.
	
	-d	Decompressor mode. This mode is used for decompressing
		a prior compressed input binary file into the original file.
