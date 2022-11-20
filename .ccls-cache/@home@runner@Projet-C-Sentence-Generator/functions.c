#include "functions.h"
#include "data.h"
#include <string.h>
#include <stdio.h>
#include <time.h>


void From_Dico_to_Tree(int line_number) //Function to find all the informations in the dictionnary and put them in the trees
{
TREE* tree = (TREE *)malloc(sizeof(TREE)); //Creating all the trees needed
tree->rootNouns = createNode('-');
tree->rootAdjectives = createNode('-');
tree->rootVerbs = createNode('-');
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
            }
        }
    insertWord(tree, non_flechie, type_dico, flechie); //Inserting the words into the trees
    } while (1);
    fclose(file);
  }


void Menu(){ //Simple menu to go through the functions, however this is just for demonstration purpose, there are no functions because we didn't manage to finish the project, except for the generation part
      printf("       =====C Project=====     \n");
    printf("=====Random Sentence Generator======\n");
    printf("     Choose what you want to do: \n  1- Generate the trees\n  2- Look for a word in a three\n  3- Generate a random sentence\n");
    int a=0;
    do{printf("Menu choice: ");
    scanf("%d", &a);
    printf("\n");
    }while((a!=1) && (a!=2) && (a!=3));
    if (a==1){
        printf("You choose option 1: Generate the trees\n");
        From_Dico_to_Tree(300000);
        printf("Sorry but we weren't able to solve all the errors in this part\nHowever, with the help of the report, you will be able to understand all the code that we did in this part\n");
    }
    if (a==2){
        printf("You choose option 2: Look for a word in a tree\n");
        printf("Sorry but we weren't able to solve all the errors in this part\nHowever, with the help of the report, you will be able to understand all the code that we did in this part\n");
    }
    if (a==3){
        printf("You choose option 3: Generate a random sentence\n");
        printf("Sorry but we weren't able to solve all the errors in this part\nHowever, with the help of the report, you will be able to understand all the code that we did in this part\n");
    }
  return;
}



char* RandomWord(TREE tree){ //finds a random word in a specific tree
  int i;
  srand(time(NULL));   // Initialization
  int nbr_letter = rand() %10; //This number can be changed to randomly generate numbers greated than 10 letters
  int letter = rand() %26;
  NODE* node = tree.root;
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
