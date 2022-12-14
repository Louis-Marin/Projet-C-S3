#include "node.h"

typedef struct s_flechie{ 
  char* word;
  struct s_flechie *next;
} FLECHIE;

typedef struct s_node{ 
  char letter;
  struct s_node** children;
  FLECHIE* head;
} NODE;

typedef struct s_tree{
  NODE* rootNouns;
  NODE* rootVerbs;
  NODE* rootAdjectives;
} TREE;

TREE* createEmptyTree();
void insertWord(TREE*, char*, char*);