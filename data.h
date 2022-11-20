#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_flechie{ 
  char* word;
  struct s_flechie *next;
} FLECHIE;

typedef struct s_node{ 
  char letter;
  struct s_node** children;
  bool end;
  FLECHIE* head;
  int nbr_Flechie;
} NODE;

typedef struct s_tree{
  NODE* rootNouns;
  NODE* rootVerbs;
  NODE* rootAdjectives;
} TREE;

NODE* createNode(char letter);
TREE* createEmptyTree();
void insertWord(TREE* tree, char* word, char* type);
int findWord(TREE* tree, char* word, char* type);
