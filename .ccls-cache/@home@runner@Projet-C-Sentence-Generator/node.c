#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

NODE* createNode(char letter){
  NODE* node = (NODE*)malloc(sizeof(NODE));
  node->letter = letter;
  //node->children = (NODE*)malloc(26 * sizeof(NODE));
  return node;
}
