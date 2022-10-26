#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
  // Declaration of the different trees
  /*
  t_tree nouns, verbs, adjectives, adverbs;
  nouns = verbs = adjectives = adverbs = createEmptyTree();
  */
  char filename = 'miniDico';
  printf("Le type est %d",type_mot(filename));
  return 0;
}