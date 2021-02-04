#include "lists.h"
/**
 * check_cycle - checks if a linked list has a cycle in it or not
 * @list: pointer to the head of the list
 * Return: 0 if there is no cycle,  otherwise 1
 */
int check_cycle(listint_t *list)
{
	listint_t *first, *second;

        if (!list)
            return (0);

	first = second = list;

	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;

		if (first == second)
			return (1);
	}

	return (0);
}

