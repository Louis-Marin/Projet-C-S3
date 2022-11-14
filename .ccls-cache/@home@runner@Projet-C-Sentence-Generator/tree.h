#include "node.h"

typedef struct s_tree{
  NODE * rootNouns;
  NODE * rootVerbs;
  NODE * rootAdjectives;
} TREE;

TREE* createEmptyTree();

/*
struct s_tree{
  p_letter_node root;
};
typedef struct s_tree t_tree, *p_tree;

typedef struct _naryTree{ // Déclaration de la structure de l'arbre et des 3 feuilles/sous-arbres pour les noms, adjectifs et verbes
    leaf* headNom;
    leaf* headAdj;
    leaf* headVerb;
}naryTree;

t_tree createEmptyTree();
void insert(t_tree, char*);
*/