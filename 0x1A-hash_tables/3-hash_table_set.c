#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index, iter;
	hash_node_t *new;

	if (!ht || !key || !value || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (iter = index; ht->array[iter]; iter++)
	{/*check if key exits in list */
		if (strcmp(ht->array[i]->key, key) == 0)
		{/*replace key value with new value*/
			free(ht->array[i]->value);
			ht->array[i]->value = strdup(value);
			return (1);
		}
	}
	/* key is new */
	new = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (!new)
		return (0);
	
	new->key = strdup(key);
	new->value = strdup(value);
	if (!new->key || !new->value)
	{
		free(new);
		return (0);
	}


	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
