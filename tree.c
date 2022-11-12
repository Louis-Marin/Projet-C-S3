#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "tree.h"
#include "node.h"

t_tree createEmptyTree(){
    t_tree tree;
    p_letter_node new = createEmptyNode();
    tree.root = new;
    return tree;
}

void insert(t_tree tree, char* word) {
  p_letter_node current = tree.root;
  for (int i = 0; i < str_size(word); i++) {
    if (current->children[word[i]] == NULL){
      current->children[word[i]] = createEmptyNode();
      current->children[word[i]]->letter = word[i];
    }
    current = current->children[word[i]];
  }
  current->end = true;
  //current->Flechie->F_Flechie = Forme_Flechie;
  //current->Flechie->temps = temps;
  //current->Flechie->genre = genre;
  //current->Flechie->nombre = nombre;
}