#include "lists.h"
/**
 * print_dlistint - prints the data in
 * dlistint_t type
 * @h: dlistint_t type head
 * Return: list size
*/


size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *curr;
	int iter;

	curr = h;
	for (iter = 0; curr; curr = curr->next, iter++)
		printf("%d\n", curr->n);
	return (iter);
}
