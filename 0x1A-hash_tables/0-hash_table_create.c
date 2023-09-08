#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 *
 * Description: function that creates a hash table
 *
 * @size: the size of the array
 *
 * Return: return NULL or Hash Table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int index;

	new_table = (hash_table_t *) malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->array = (hash_node_t **) malloc(sizeof(hash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}
	for (index = 0; index < size; index++)
		(new_table->array)[index] = NULL;
	return (new_table);
}
