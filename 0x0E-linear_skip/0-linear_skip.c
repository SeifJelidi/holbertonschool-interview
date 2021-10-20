#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integer
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: node with searched value or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr;
	skiplist_t *q;

	if (list == NULL)
		return (NULL);

	curr = list->express;
	q = list;
	while (curr)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n >= value)
			break;

		q = curr;
		if (curr->express == NULL)
		{
			while (curr->next)
				curr = curr->next;
			break;
		}
		curr = curr->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		q->index, curr->index);
	while (q && q->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", q->index, q->n);
		if (q->n == value)
			return (q);
		q = q->next;
	}
	return (NULL);
}
