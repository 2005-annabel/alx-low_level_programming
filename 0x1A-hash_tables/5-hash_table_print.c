#include "hash_tables.h"
/**
 * hash_table_print - this prints the hash table
 * @ht: this is the hash table pointer to print
 *
 * Return: returns key value pairs in their sequential order
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *new_node;
	/* waiting for data to be printed */
	char new_flag = 0;
	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		new_node = ht->array[i];
		while (new_node != NULL)
		{
			if (new_flag == 1)
				printf(", ");
			printf("'%s': '%s'", new_node->key, new_node->value);
			new_flag = 1;
			new_node = new_node->next;
		}
	}
	printf("}\n");
}
