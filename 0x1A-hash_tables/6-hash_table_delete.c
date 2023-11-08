#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to be deleted.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;

	if (ht == NULL)
	{
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *current = ht->array[i];

		while (current != NULL)
		{
			hash_node_t *temp = current; /* Store the current node temporarily*/

			current = current->next; /* Move to the next node.*/

			free(temp->key); /* Free the memory for the key.*/
			free(temp->value); /* Free the memory for the value.*/
			free(temp); /*Free the memory for the current node.*/
		}
	}

	free(ht->array); /*Free the memory for the array of buckets.*/
	free(ht); /*Free the memory for the hash table structure itself */
}
