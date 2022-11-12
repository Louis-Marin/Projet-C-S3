#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int str_size(char* word) {
    int count; 
    for (count = 0; word[count] != '\0'; ++count);
    return count; 
}

void get_info(int line_number) 
{
  char* flechie;
  char* non_flechie;
  char type_dico;
  char new_c;
  int tabs = 0;
  int nbline = 0;
  FILE *file = fopen("miniDico.txt", "r");
  if (file == NULL) 
  {
    printf("file not open\n");
    return;
  }

  do {
    if (nbline == line_number)
      break;
    if (tabs == 0 )
    {
      new
      strncat(flechie, new_c,1);
    }
    if (tabs == 2) {
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
