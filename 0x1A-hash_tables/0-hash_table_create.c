#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	unsigned long int index;

	/* allocate table memory */
	table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (!table)
		return (NULL);

	table->size = size;

	/* allocate table  array memory */
	table->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (!table->array)
		return (NULL);

	/* initialize table array */
	for (index = 0; index < size; index++)
		table->array[index] = NULL;

	return (table);
}
