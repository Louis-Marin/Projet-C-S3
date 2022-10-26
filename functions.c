#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int type_mot(char file_name)
{
  char type_dico;
  int tabs = 0;
  FILE* file=NULL;
  char letter;
  file = fopen("file_name", "r");
  if (file == NULL)
  {
    printf("file not open");
  }
  if (file != NULL)
    {
        do
        {
            letter = fgetc(file);
          if (tabs == 2)
          {
            type_dico = fgetc(file);
            type_dico = fgetc(file);
            type_dico = fgetc(file);
            tabs = 0;
          }
            printf("%c", letter);
          if (letter == '\t')
          {
            tabs++;
          }
        }
          while (letter != EOF);
 
        fclose(file);
    switch(type_dico)
    {
    case 'j':
      return 1;
    case 'm':
      return 2;
    case 'r':
      return 3;
    case 'v':
      return 4;
        }
}
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
