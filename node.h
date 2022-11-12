#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26


struct Forme_Flechie{
  char* F_Flechie, temps;
  int genre, nombre;
};
typedef struct Forme_Flechie FF;

struct s_letter_node{
  struct s_letter_node* children[ALPHABET_SIZE];
	char letter;
  bool end;
  FF Flechie;
};
typedef struct s_letter_node t_letter_node, *p_letter_node;


p_letter_node createEmptyNode();