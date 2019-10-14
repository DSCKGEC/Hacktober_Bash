/*This file contains the function definitions of functions used while compressing*/

#ifdef _WIN32
#include "..\..\includes\commons.h"
#include "..\..\includes\compressor.h"
#else
#include "../../includes/commons.h"
#include "../../includes/compressor.h"
#endif

void c_clear_tree(c_node *tree){
	if(tree != NULL){
		c_clear_tree(tree -> LEFT);
		c_clear_tree(tree -> RIGHT);
		free(tree);
		tree = NULL;
	}
}

void c_shift_down(c_node *arr, char num_of_characters, char id){
	//Forms minheap
	if(id < num_of_characters >> 1){
		char left = id + id + 1;
		char right = left + 1;
		char min_id;
		if(right < num_of_characters && arr[right].frequency < arr[left].frequency) min_id = right;
		else min_id = left;
		if(arr[id].frequency < arr[min_id].frequency) min_id = id;
		if(id != min_id){
			//Swap
			c_node temp = arr[id];
			arr[id] = arr[min_id];
			arr[min_id] = temp;
			//heapify rest recursively
			c_shift_down(arr, num_of_characters, min_id);
		}
	}
}

void c_heapify(c_node *arr, char num_of_characters){
	//Forms minheap
	char i;
	for(i = num_of_characters >> 2 - 1; i >= 0; --i)
		c_shift_down(arr, num_of_characters, i);
}

c_node c_pop_from_minheap(c_node *minheap, char *num_of_characters){
	//pops minimum element from minheap
	c_node ITEM = minheap[0];
	minheap[0] = minheap[--(*num_of_characters)];
	c_shift_down(minheap, *num_of_characters, 0);
	return ITEM;
}

void c_make_huffman_tree(c_node *minheap, char *num_of_characters){
	//Generates huffman tree from nodes of minheap
	if(*num_of_characters > 1){
		//ITEM1 = c_pop()
		c_node *ITEM1 = (c_node *) malloc(sizeof(c_node));
		*ITEM1 = c_pop_from_minheap(minheap, num_of_characters);//*num_of_characters -= 1
		//ITEM2 = minheap[0]
		c_node *ITEM2 = (c_node *) malloc(sizeof(c_node));
		*ITEM2 = minheap[0];
		//ITEM_IN = f(ITEM1, ITEM2)
		minheap[0].character = 0;
		minheap[0].frequency = ITEM1 -> frequency + ITEM2 -> frequency;
		minheap[0].LEFT = ITEM1;
		minheap[0].RIGHT = ITEM2;
		//c_shift_down(minheap, num_of_characters, 0)
		c_shift_down(minheap, *num_of_characters, 0);
		c_make_huffman_tree(minheap, num_of_characters);
	}
}

void c_print_huff_preorder(c_node *arr){
	if(arr != NULL){
		printf("%c", arr -> character);
		c_print_huff_preorder(arr -> LEFT);
		c_print_huff_preorder(arr -> RIGHT);
	}
}

void c_print_huff_inorder(c_node *arr){
	if(arr != NULL){
		c_print_huff_inorder(arr -> LEFT);
		printf("%c", arr -> character);
		c_print_huff_inorder(arr -> RIGHT);
	}
}

void c_push(c_stack *stk, char ITEM){
	stk -> arr[++(stk -> TOP)] = ITEM;
}

char c_pop(c_stack *stk){
	if(stk -> TOP < 0)
		return -1;
	char ITEM = stk -> arr[stk -> TOP];
	--(stk -> TOP);
	return ITEM;
}

void c_encoder(c_node *tree, c_stack *stk, c_enc *initial_frequency_arr){
	if(tree != NULL){
		if(tree -> LEFT == NULL && tree -> RIGHT == NULL){
			printf("'%c': ", tree -> character);
			char iter = 0;
			while(iter <= stk -> TOP){
				(initial_frequency_arr[tree -> character]).encoded[iter] = stk -> arr[iter] + '0';
				++iter;
			}
			(initial_frequency_arr)[tree -> character].encoded[iter] = '\0';
			printf("%s", (initial_frequency_arr[tree -> character]).encoded);
			printf("\n");
		}
		c_push(stk, 0);
		c_encoder(tree -> LEFT, stk, initial_frequency_arr);
		c_pop(stk);
		c_push(stk, 1);
		c_encoder(tree -> RIGHT, stk, initial_frequency_arr);
		c_pop(stk);
	}
}

void c_print_char(char ch){
	char index = 7;
	while(index >= 0){
		printf("%d", (ch >> index) & 1);
		--index;
	}
	printf("\t");
}