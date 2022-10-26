#include "node.h"

struct s_tree{
  p_letter_node root;
};
typedef struct s_tree t_tree, *p_tree;

t_tree createEmptyTree();
void AddChildren(char, t_tree*, p_letter_node);