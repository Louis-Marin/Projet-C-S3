#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "tree.h"

void insertWord(TREE* tree, char* word, char* type){
  NODE* node;
  if (strcmp(type,"Nom")){
    node = tree->rootNouns;
  } else if (strcmp(type,"Ver")){
    node = tree->rootVerbs;
  } else if (strcmp(type,"Adj")){
    node = tree->rootAdjectives;
  }  else{
    printf("[!] Wrong word type, ending task.\n");
    exit(101);
  }
  for(int i = 0; i < strlen(word); i++){
    char chr = word[i];
    //printf("%d", chr - 'a');
    //printf("%c", chr);
    if(node->children[chr - 'a'] == NULL){
      node->children[chr - 'a'] = createNode(chr);
    }
    node = node->children[chr - 'a'];
  }
}



