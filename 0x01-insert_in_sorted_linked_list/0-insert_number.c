#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the head of the list
 * @number: n element of the new node.
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *q;
	listint_t *node;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);

	node->n = number;

	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
		return (node);
	}

	q = *head;

	if (q->n > number)
	{
		node->next = q;
		*head = node;
		return (node);
	}

	while (q->next && q->next->n < number)
	{
		q = q->next;
	}

	node->next = q->next;
	q->next = node;

	return (node);
}
