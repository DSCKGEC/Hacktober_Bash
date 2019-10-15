/*This file contains the preprocessor directives for decompression*/

#ifndef _DECOMPRESSOR_H_
#define _DECOMPRESSOR_H_

/*This structure is used to hold
 elements for Huffman tree*/
typedef struct d_node{
	char character;
	struct d_node *LEFT;
	struct d_node *RIGHT;
}d_node;

/*This function clears
 Huffman tree*/
void d_clear_tree(d_node *);

/*Prints a character in binary*/
void d_print_char(char);

/*Makes Huffman tree*/
void d_make_tree(d_node *, FILE *, char, char);

/*Inorder traversal of Huffman tree*/
void d_inorder(d_node *);

/*Postorder traversal of Huffman tree*/
void d_preorder(d_node *);

/*Decompresses input file*/
void decompressor(char *, char *);

#endif	//_DECOMPRESSOR_H_