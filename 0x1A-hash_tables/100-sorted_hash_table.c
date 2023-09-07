#include "hash_tables.h"
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
/**
 * shash_table_create - this creates a sorted out hash table.
 * @size: shows the available size of the hash table.
 *
 * Return: it returns a pointer to the created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	ht = malloc(sizeof(*ht));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = calloc(size, sizeof(*ht->array));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}
/**
 * shash_table_set - this adds an element to the sorted hash table.
 * @ht: this shows a pointer to the sorted hash table.
 * @key: adds a key.
 * @value: shows the value associated with key.
 *
 * Return: should return 1 on success and 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *val_cpy;
	unsigned long int idx;
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	val_cpy = strdup(value);
	if (val_cpy == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->snext;
	if (tmp != NULL)
	{
		free(tmp->value);
		tmp->value = val_cpy;
		return (1);
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		free(val_cpy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(val_cpy);
		free(new);
		return (0);
	}
	new->value = val_cpy;
	new->next = ht->array[idx];
	ht->array[idx] = new;
	insert_sorted_node(ht, new);
	return (1);
}
/**
 * insert_sorted_node - these line then inserts a node into a sorted hash table.
 * @ht: this is a pointer to the sorted hash table.
 * @new: it shows te new node to insert.
 */
void insert_sorted_node(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;
	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
		return;
	}
	if (strcmp(ht->shead->key, new->key) >= 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext != NULL && strcmp(tmp->snext->key, new->key) < 0)
		tmp = tmp->snext;
	new->sprev = tmp;
	new->snext = tmp->snext;
	if (tmp->snext == NULL)
		ht->stail
