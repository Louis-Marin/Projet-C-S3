#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
  TREE* tree = (TREE *)malloc(sizeof(TREE));
  tree->rootNouns = createNode('-');
  tree->rootAdjectives = createNode('-');
  tree->rootVerbs = createNode('-');
  
  printf("Works.\n");
  get_info(10);
  return 0;
}