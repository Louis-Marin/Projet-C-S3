#include "functions.h"
#include "tree.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int str_size(char* word) {  //computes the size of a string
    int count; 
    for (count = 0; word[count] != '\0'; ++count);
    return count; 
}

void get_info(int line_number) //Find the info of the words in the dictionnary
{
    char flechie[26];
    char non_flechie[26];
    char type_dico[26];
  //Make sure the variables are empty
    non_flechie[0] = '\0';
    flechie[0] = '\0';
    type_dico[0] = '\0';
    char new_c;
    int tabs = 0;
    int nbline = 0;
    int i = 0;
    FILE *file = fopen("miniDico.txt", "r");
    if (file == NULL)
    {
        printf("file not open\n");
        return;
    }
    do {
        if (nbline == line_number ) {
            break;
        }
        if (tabs == 0 )
        {
            new_c = fgetc(file);
            if (new_c == '\t')
            {
                tabs++;
            }
            else
                strncat(flechie, &new_c,1);
        }
        if (tabs == 1 )
        {
            new_c=fgetc(file);
            if (new_c == '\t')
            {
                tabs++;
            }
            else
                strncat(non_flechie, &new_c,1);
        }
        if (tabs == 2)
        {
            while (i < 3)
            {
                new_c = fgetc(file);
                strncat(type_dico, &new_c,1);
                i++;
            }
            new_c = fgetc(file);
            if (new_c == '\n')
            {
                nbline++;
                i=0;
                tabs=0;
                printf("%s - ",flechie);
                printf("%s - ",non_flechie);
                printf("%s \n",type_dico);
                non_flechie[0] = '\0';
                flechie[0] = '\0';
                type_dico[0] = '\0';
                //strcpy(non_flechie,"");
                //strcpy(flechie,"");
                //strcpy(type_dico,"");
                // add_nonflechie(non_flechie);
                // add_flechie(flechie);
                // add_type(type_dico);
            }
        }
    } while (1);

    fclose(file);
  }
/*
void mainMenu(){
  printf("----------------------\n"
  "| Sentence Generator |\n"
  "----------------------\n"
  "1. Generate a Sentence\n"
  "2. Credits\n"
  "3. Quit Program\n"
  "----------------------\n"
  );
}
*/

/*


char* RandomWord(t_tree tree){ //finds a random word in a specific tree
  int i;
  srand(time(NULL));   // Initialization
  int nbr_letter = rand() %10;
  int letter = rand() %26;
  p_letter_node node = tree.root;
  char* RandomWord;
  for (i=0; i<nbr_letter; i++){
    while(node->children[letter]==NULL){
      letter = rand() %26;
    }
      RandomWord[i] = node->children[letter];
      int letter = rand() %26;
      node = node->children[letter];
  }
  while (!(node->children[letter]->end)){
    int letter = rand() %26;
  }
  RandomWord[i+1] = node->children[letter];
  return RandomWord;
}

int FindWord(t_tree tree){
  char* word;
  printf("Enter the word you want to search in the tree: \n");
  scanf("%s", word);
  t_letter_node node;
  node = tree.root;
  size = str_size(word);
  for (int i=0; i<size; i++){
    if (node.children[i]==NULL){
      return 0;
    }
    node = node.children[i];
  }
  return 1;
}

*/