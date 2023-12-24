#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int i;

	/*free array elements or lists*/
	for (i = 0; i < ht->size; i++)
	{/*if node list head is not empty*/
		if (ht->array[i] != NULL)
		{/*advance and free*/
			node = ht->array[i];
			while (node != NULL)
			{
				tmp = node->next; /*reference to nxt node */
				free(node->key);
				free(node->value);
				free(node);
				node = tmp; /*move to nxt node*/
			}
		}
	}
	/*free array and table memory*/
	free(head->array);
	free(head);
}
