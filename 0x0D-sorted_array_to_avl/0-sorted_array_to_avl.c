#include "binary_trees.h"

/**
 * new_node - the new node
 * @parent: avl_t
 * @n: the valur of node
 * Return: return the new node
 */
avl_t *new_node(avl_t *parent, int n)
{
avl_t *node = malloc(sizeof(avl_t));

if (!node)
return (NULL);

	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sort_data - convert the array
 * @array: sorted
 * @start: start of index
 * @end: end of index
 * @parent: the parent npde
 * Return: avl tree
 */
avl_t *sort_data(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;
		if (start > end)

			return (NULL);
	mid = (start + end) / 2;

	root = new_node(parent, array[mid]);

	if (start != mid)
		root->left = sort_data(array, start, mid - 1, root);

	if (end != mid)
		root->right = sort_data(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - covert array
 * @array: the pointer of the start
 * @size: size of the array
 * Return: the avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size < 1)
		return (NULL);

	root = sort_data(array, 0, size - 1, NULL);

	return (root);
}
