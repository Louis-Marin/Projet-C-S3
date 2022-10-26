#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


t_tree createStarterTree(){
    t_tree tree;
    p_letter_node new = createNode(' ');
    tree.root = new;
    return tree;
}

void AddChildren(char letter, t_tree* tree, p_letter_node new){
  int val = letter;
  new->children[val] = createNode(letter);
}
