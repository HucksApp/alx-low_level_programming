#include "lists.h"

/**
 * createNode - creates new node
 * @num: number
 * Return: pointer to the new node
 */
dlistint_t *createNode(int num)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	node->n = num;
	node->next = NULL;
	node->prev = NULL;
	if (!node)
		return (NULL);
	return (node);
}

/**
 * add_dnodeint -  appends node
 * @head: dlistint_t type head
 * @n: number
 * Return: pointer to added node
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *curr, *node;

	/*the head pointer is pointing to Null i.e no head*/
	if (!head)
		return (NULL);

	node = createNode(n);
	if (!node)
		return (NULL);

	curr = *head;
	/* the head is pointing to NULL*/
	if (!curr)
	{ /*new node is the first and last node */
		*head = node;
		return (node);
	}
	/*head is pointing to first node i.e curr is at first node */
	while (curr->prev != NULL)
		curr = curr->prev;

	node->next = curr; /*new node is 1st node*/
	curr->prev = node;/*curr or former first node is now second node*/
	*head = node;/* point head to new first node */
	return (node);
}
