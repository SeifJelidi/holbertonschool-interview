#include "lists.h"
/**
 * is_palindrome - checks if a linked list is palindrome
 *
 * @head: Head node
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{
int i, n, c = 0, m;
listint_t *start, *end;

if (head == NULL)
return (1);

start = (listint_t *)malloc(sizeof(listint_t));
end = (listint_t *)malloc(sizeof(listint_t));
start = *head;
end = *head;

while (end->next)
{
n = n + 1;
end = end->next;
}
m = n;
while (i < n / 2)
{
if (end->n != start->n)
return (0);
else
{
start = start->next;
end = *head;
m = m - 1;
while (c < m)
{
c = c + 1;
end = end->next;
}
c = 0;
}
i++;
}
return (1);
}
