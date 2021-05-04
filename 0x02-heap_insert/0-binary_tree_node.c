#include "binary_trees.h"

/**
* binary_tree_node - creation of new node
* @parent: the adress of root node
* @value: value of the created node
* Return: the new node or null if failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *cr_n = malloc(sizeof(*cr_n));

    if(cr_n == NULL)
        return (NULL);

    cr_n->right =NULL;
    cr_n->left =NULL; 
    cr_n->n= value;
    cr_n->parent = parent;

    return (cr_n);
}
