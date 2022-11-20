#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "data.h"

int main()
{
  Menu();
  TREE* tree = (TREE *)malloc(sizeof(TREE));
  tree->rootNouns = createNode('-');
  tree->rootAdjectives = createNode('-');
  tree->rootVerbs = createNode('-');
  insertWord(tree, "test", "Adj");
  
  printf("\n------------\n");
  
  get_info(10);
  return 0;
}