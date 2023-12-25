#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int index;

	table = (shash_table_t *)malloc(sizeof(shash_table_t));
	if (!table)
		return (NULL);

	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	/*set bucket head mem*/
	table->array = (shash_node_t **)malloc(sizeof(shash_node_t *) * size);
	if (!table->array)
		return (NULL);

	/*init bucket heads*/
	for (index = 0 ; index == size; index++)
		table->array[index] = NULL;
	return (table);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp, *prev;
	unsigned long int index;


	if (!ht || !key || !value || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	if (ht->shead)
	{/*the nodes head is not empty*/
		tmp = ht->shead;
		while (tmp)
		{/*check if key exists*/
			if (strcmp(tmp->key, key) == 0)
			{/* replace */
				free(tmp->value);
				tmp->value = strdup(value);
				return (1);
			}
			tmp = tmp->snext;
		}
	}
	/* its new*/
	new = (shash_node_t *)malloc(sizeof(shash_node_t));
	if (!new)
	{
		free(new);
		return (0);
	}
	new->key = strdup(key);
	new->value = strdup(value);
	if (!new->key || !new->value)
	{
		free(new);
		return (0);
	}
	new->next = ht->array[index]; /*insert at top*/
	ht->array[index] = new;
	if (!ht->shead)
	{/* no head node yet, definately no tail*/
		new->sprev = NULL; /* mark start */
		new->snext = NULL; /* mark end */
		ht->shead =  new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, new->key) > 0)
	{/* Ascending order: new key is smaller than old key */
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new; /*new is new shead  */
	}
	else
	{/* new key is bigger than the old key*/
		/*new is new stail  or just insert new in ranked position*/
		tmp = ht->shead;
		while (tmp && strcmp(tmp->key, key) < 0)
		{
			prev = tmp; /*rev to prev node before last node or null*/
			tmp = tmp->snext; /*move to insertion point*/
		}
		if (tmp)
		{ /* new is not tail, just insert*/
			new->sprev = tmp->sprev;
			tmp->sprev->snext  = new;
			new->snext = tmp;
			tmp->sprev = new;
		}
		else
		{/* new is  tail*/
			prev->snext = new;
			new->sprev = prev;
			new->snext = NULL;
			ht->stail = new;
		}
	}
	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (!ht || !key  || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->snext;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}
