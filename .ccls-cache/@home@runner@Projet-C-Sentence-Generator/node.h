#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26

typedef struct s_node{ 
    char letter;
    struct s_node * children;
} NODE;

NODE* createNode(char letter);


/*

typedef struct _flechie{ // Déclaration de la structure de stockage des formes fléchies
    char * str;
    struct _flechie * next;
}flechie;

struct s_letter_node{ //structures des nodes
  struct s_letter_node* children[ALPHABET_SIZE];
	char letter;
  bool end;
  flechie ff;
  int nbFlechie;
};
typedef struct s_letter_node t_letter_node, *p_letter_node;


p_letter_node createEmptyNode();

*/