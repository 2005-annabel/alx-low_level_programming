#include "hash_tables.h"
/**
 * create_hash_node - this creates a new hash node
 * @key: is the key for the node created
 * @value: is the value for the node
 *
 * Return: returns the new node
 */
hash_node_t *create_hash_node(const char *key, const char *value)
{
	hash_node_t *new_node;
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}
/**
 * hash_table_set - creates sets of a key to a value in the hash table
 * @ht: adds elsemnt to the hash table.
 * @key: this is the key for the data
 * @value: the data available for storing
 *
 * Return: the return value is i if successful or 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *hash_node, *new_val;
	char *newest_value;
	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
			key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	new_val = ht->array[index];
	while (new_val != NULL)
	{
		if (strcmp(new_val->key, key) == 0)
		{
			newest_value = strdup(value);
			if (newest_value == NULL)
				return (0);
			free(new_val->value);
			new_val->value = newest_value;
			return (1);
		}
		new_val = new_val->next;
	}
	hash_node = create_hash_node(key, value);
	if (hash_node == NULL)
		return (0);
	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;
	return (1);
}
