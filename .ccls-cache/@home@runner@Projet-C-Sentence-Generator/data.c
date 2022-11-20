#include <stdio.h>
#include "data.h"




NODE* createNode(char letter){
  NODE* node = (NODE*)malloc(sizeof(NODE));
  node->letter = letter;
  node->children = (NODE**)malloc(26 * sizeof(NODE));
  return node;
}

FLECHIE* createFlechie(char* word){
  FLECHIE* flechie;
  flechie->word = word;
  flechie->next = NULL;
  return flechie;
}

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
  node->nbr_Flechie++;
}

int isEmptyList(NODE* node){
  if (node->head == NULL){
    return 1;
  } else{
    return 0;
  }
}

void addflechie(NODE* node, char* flechie){
  if (isEmptyList(node) == 1){
    FLECHIE* newFlechie = createFlechie(flechie);
    node->head = newFlechie;
  } else{
    FLECHIE* temp = node->head;
    while (temp->next != NULL){
			temp = temp->next;
		}
    FLECHIE* newFlechie = createFlechie(flechie);
    temp->next = newFlechie;
  }
}

int findWord(TREE* tree, char* word, char* type){
  NODE* node;
  if (strcmp(type,"Nom") == 0){
    node = tree->rootNouns;
  } else if (strcmp(type,"Ver") == 0){
    node = tree->rootVerbs;
  } else if (strcmp(type,"Adj") == 0){
    node = tree->rootAdjectives;
  }  else{
    printf("[!] Wrong word type, ending task.\n");
    exit(101);
  }
  int size = strlen(word);
  for (int i = 0; i < size; i++){
    char chr = word[i];
    if (node->children[chr - 'a'] == NULL){
      return 0;
    }
    node = node->children[chr - 'a'];
  }
  return 1;
}