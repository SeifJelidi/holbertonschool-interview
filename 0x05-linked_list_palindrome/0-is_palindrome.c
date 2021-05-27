#include "lists.h"
/**
 * is_palindrome - checks if a linked list is palindrome
 * @head: Head node
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{
int i, n = 0;
int m;
int tab[1900];

if (*head == NULL)
return (1);

while (*head)
{
tab[n] = (*head)->n;
*head = (*head)->next;
n = n + 1;
}
m = n / 2;
while (i <= m)
{
if (tab[i] != tab[n])
return (0);
++i;
--n;
}
return (1);
}
