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

	/* head pointer is pointing to NULL i.e no head */
	if (!head)
		return (NULL);

	/* head is pointing to NULL i.e no node in list*/
	if (!(*head))
	{
		/*iadd node as first node*/
		node = createNode(n);
		if (!node)
			return (NULL);

		(*head) = node;
		return (node);
	}

	/* list is not empty, add node as 1st node*/
	curr = *head;
	node = createNode(n);

	if (curr != NULL)
		while(curr->prev != NULL)
			curr = curr->prev;
	if (!node)
		return (NULL);
	*head = node;
	node->next = curr;
	curr->prev = node;
	return (node);
}
