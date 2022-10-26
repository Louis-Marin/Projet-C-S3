#include <stdio.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26

struct s_letter_node{
	char letter;
  struct s_letter_node* children[ALPHABET_SIZE];
};
typedef struct s_letter_node t_letter_node, *p_letter_node;

p_letter_node createNode(char);