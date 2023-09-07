#include "hash_tables.h"
/**
 * command hash_table_create - is used to create a hash table
 * @size: the size of the array
 * Return: pointer to new hash table or NULL if an error occurs
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_t;
	unsigned long int i;
	/* determine size of array */
	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
		return (NULL);
	hash_t->size = size;
	hash_t->array = malloc(size * sizeof(hash_node_t *));
	if (hash_t->array == NULL)
	{
		/* free up the memory space to avoid leaks */
		free(hash_t);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		hash_t->array[i] = NULL;
	return (hash_t);
}
