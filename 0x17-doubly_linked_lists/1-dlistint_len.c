#include "lists.h"

/**
 * dlistint_len -  calculate the dlistint_t type
 * length
 * @h: dlistint_t type head
 * Return: list length
*/

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *curr;
	int count;

	curr = h;
	for (count = 0; curr; curr = curr->next, count++)
		;
	return (count);
}
