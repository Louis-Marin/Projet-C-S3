#include <stdio.h>
#include "data.h"




NODE* createNode(char letter){ //Function to create the Nodes, hen created they are empty
  NODE* node = (NODE*)malloc(sizeof(NODE)); //dynamic memory allocation for the node
  node->letter = letter;
  node->children = (NODE**)malloc(26 * sizeof(NODE)); //dynamic allocation for all the children
  return node;
}

FLECHIE* createFlechie(char* word){ //Function for the Formes Fléchies
  FLECHIE* flechie;
  flechie->word = word; 
  flechie->next = NULL; //Definition of the linked list for all the formes fléchies
  return flechie;
}

void insertWord(TREE* tree, char* word, char* type, char* wordf){ //Function to insert a word in the tree, this function is used to create all the rtees
  NODE* node;
  if (strcmp(type,"Nom")){ //This part is to choose the right to tree to insert the word
    node = tree->rootNouns;
  } else if (strcmp(type,"Ver")){
    node = tree->rootVerbs;
  } else if (strcmp(type,"Adj")){
    node = tree->rootAdjectives;
  }  else{
    printf("[!] Wrong word type, ending task.\n"); //error printing
    exit(101);
  }
  for(int i = 0; i < strlen(word); i++){ // adds the word character by character
    char chr = word[i];
    //printf("%d", chr - 'a');
    //printf("%c", chr);
    if(node->children[chr - 'a'] == NULL){
      node->children[chr - 'a'] = createNode(chr); //In this part we verify that the node doesn't exist, if it doesn't then we create it
    }
    node = node->children[chr - 'a']; //If the node is created or it was already there, we go frther down into the tree to keep inserting the letters of the word
  }
  addflechie(node, wordf); //This function is to add the forme fléchie
}

int isEmptyList(NODE* node){ //Function to find is a list is empty or not
  if (node->head == NULL){
    return 1;
  } else{
    return 0;
  }
}

void addflechie(NODE* node, char* flechie){ //Function to add the forme fléchie
  if (isEmptyList(node) == 1){
    FLECHIE* newFlechie = createFlechie(flechie); //Creating the new node of the SLL
    node->head = newFlechie;
  } else{
    FLECHIE* temp = node->head;
    while (temp->next != NULL){
			temp = temp->next; //Going thourght the list to store it at the end
		}
    FLECHIE* newFlechie = createFlechie(flechie);
    temp->next = newFlechie; //inserting the node at the right emplacement
  }
  return;
}


int findWord(TREE* tree, char* word, char* type){ //Function to find the word in a tree
  NODE* node;
  if (strcmp(type,"Nom") == 0){  //This part is to choose the right to tree to insert the word
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
    if (node->children[chr - 'a'] == NULL){ //If a letter of the word isn't in the tree, we automatically return 0, because the word isn't in the tree
      return 0;
    }
    node = node->children[chr - 'a'];
  }
  return 1; //if all the letters are in the tree, then we return 1
}