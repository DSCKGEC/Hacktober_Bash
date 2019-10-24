# HuffCrypt

## PURPOSE OF APPLICATION
This application demonstrates the compression/decompression of files with strictly ASCII characters via Huffman encryption/decompression technique.

## Compilation and Setup

### For Windows:
	gcc -std=c99 -Ofast .\src\compressor\* .\src\decompressor\* .\src\huffcrypt.c -o HuffCrypt

### For Linux:
	gcc -std=c99 -Ofast ./src/compressor/* ./src/decompressor/* ./src/huffcrypt.c -o HuffCrypt

[Note: Add the current directory to the PATH in environment variables.]

## USAGE

	HuffCrypt [-c | -d] [input file] [output file]

	-c	Compressor mode. This mode is used for compressing
		an input file with only ASCII characters into a binary file.
	
	-d	Decompressor mode. This mode is used for decompressing
		a prior compressed input binary file into the original file.
