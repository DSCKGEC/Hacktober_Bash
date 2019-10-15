/*This file contains the preprocessor directives for compression*/

#ifndef _COMPRESSOR_H_
#define _COMPRESSOR_H_

#define STACK_LENGTH 126

/*This structure is used to hold
 elements for Huffman tree*/
typedef struct c_node{
	char character;
	int frequency;
	struct c_node *LEFT;
	struct c_node *RIGHT;
}c_node;

/*This structure is used to implement
 a stack used in function encoding*/
typedef struct c_stack{
	char arr[STACK_LENGTH];
	char TOP;
}c_stack;

/*This structure is used for encoding*/
typedef struct c_enc{
	int frequency;
	char encoded[127];
}c_enc;

/*This function clears
 Huffman tree*/
void c_clear_tree(c_node *);

/*Shifts down the heap
 elements during heapify process*/
void c_shift_down(c_node *, char, char);

/*Heapifies input arr*/
void c_heapify(c_node *, char);

/*Pops top item form
 minheap(minimum element)*/
c_node c_pop_from_minheap(c_node *, char *);

/*Makes Huffman tree*/
void c_make_huffman_tree(c_node *, char *);

/*Prints Huffman tree in preorder*/
void c_print_huff_preorder(c_node *);

/*Prints Huffman tree in inorder*/
void c_print_huff_inorder(c_node *);

/*Pushes element on stack*/
void c_push(c_stack *, char);

/*Pops topmost elements from stack*/
char c_pop(c_stack *);

/*Encodes characters of input text file
 into their corresponding Huffman codes*/
void c_encoder(c_node *, c_stack *, c_enc *);

/*Prints a character in binary*/
void c_print_char(char);

/*Compresses the input file*/
void compressor(char *, char *);

#endif	//_COMPRESSOR_H_