#include <stdio.h>
#include <stdlib.h>
#include "node.h"


p_letter_node createNode(char letter){
  p_letter_node new;
  new->letter = letter;
  for (int i=0; i<=26; i++){
    new->children[i] = NULL;
  }
  return new;
}
