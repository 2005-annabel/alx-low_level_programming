#include "hash_tables.h"
/**
 * hash_table_delete - this function deletes a hash table.
 * @ht: this is a pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *new_node, *new_tmp;
	unsigned long int i;
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			new_node = ht->array[i];
			while (new_node != NULL)
			{
				new_tmp = new_node->next;
				free(new_node->key);
				free(new_node->value);
				free(new_node);
				new_node = new_tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
