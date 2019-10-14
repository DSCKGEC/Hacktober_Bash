/*This file contains the function definitions of functions used while decompressing*/
#ifdef _WIN32
#include "..\..\includes\commons.h"
#include "..\..\includes\decompressor.h"
#else
#include "../../includes/commons.h"
#include "../../includes/decompressor.h"
#endif

void d_clear_tree(d_node *tree){
	if(tree != NULL){
		d_clear_tree(tree -> LEFT);
		d_clear_tree(tree -> RIGHT);
		free(tree);
		tree = NULL;
	}
}

void d_print_char(char ch){
	char index = 7;
	while(index >= 0){
		printf("%d", (ch >> index)&1);
		--index;
	}
}

void d_make_tree(d_node *tree, FILE *cfile, char character, char encoded_len){
	char ch_buf, pos_buf = 0, scanned;
	fread(&ch_buf, sizeof(ch_buf), 1, cfile);
	while(encoded_len){
		if(pos_buf == 8){
			fread(&ch_buf, sizeof(ch_buf), 1, cfile);
			d_print_char(ch_buf);
			printf("\t");
			pos_buf = 0;
		}
		scanned = (ch_buf >> pos_buf) & 1;
		d_print_char(scanned);
		printf("\t");
		if(scanned == 0){
			if(tree -> LEFT == NULL){
				d_node *NEW = (d_node *) malloc(sizeof(d_node));
				NEW -> character = 0;
				NEW -> LEFT = NULL;
				NEW -> RIGHT = NULL;
				tree -> LEFT = NEW;
			}
			tree = tree -> LEFT;
		}else{
			if(tree -> RIGHT == NULL){
				d_node *NEW = (d_node *) malloc(sizeof(d_node));
				NEW -> character = 0;
				NEW -> LEFT = NULL;
				NEW -> RIGHT = NULL;
				tree -> RIGHT = NEW;
			}
			tree = tree -> RIGHT;
		}
		--encoded_len;
		++pos_buf;
	}
	tree -> character = character;
	printf("||||||||\t");
}

void d_inorder(d_node *tree){
	if(tree != NULL){
		d_inorder(tree ->  LEFT);
		printf("%c", tree -> character);
		d_inorder(tree -> RIGHT);
	}
}

void d_preorder(d_node *tree){
	if(tree != NULL){
		printf("%c", tree -> character);
		d_preorder(tree ->  LEFT);
		d_preorder(tree -> RIGHT);
	}
}