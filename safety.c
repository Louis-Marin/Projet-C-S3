#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
int type_mot(int line_number) 
{
  char type_dico;
  int tabs = 0;
  int nbline = 0;
  FILE *file = fopen("miniDico.txt", "r");
  if (file == NULL) 
  {
    printf("file not open\n");
    return 0;
  }

  do {
    if (nbline == line_number)
      break;
    if (tabs == 2) 
    {
      type_dico = fgetc(file);
      type_dico = fgetc(file);
      type_dico = fgetc(file);
      tabs = 0;
    }
    char letter = fgetc(file);
    if (tabs == 1 && nbline == line_number - 1) {
      printf("%c", letter);
      // add_letter(letter);
    }
    if (letter == '\n') {
      nbline++;
    }
    // printf("%c", letter);
    if (letter == '\t') {
      tabs++;
    }
    if (feof(file))
      break;
  } while (1); 

  fclose(file);
  switch (type_dico) {
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

*/