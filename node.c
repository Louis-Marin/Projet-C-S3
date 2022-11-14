#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

NODE * createNode(char letter){
  NODE * node = (NODE *)malloc(sizeof(NODE));
  node->letter = letter;
  return node;
}

