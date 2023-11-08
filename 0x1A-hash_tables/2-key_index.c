#include "hash_tables.h"
/**
 * key_index - returns the index of the key
 * @key: the literal key
 * @size: the size of the hash map
 * Return: the index
 *
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int i, j;

	i = hash_djb2(key);

	j = (i % size);

	return (j);

}
