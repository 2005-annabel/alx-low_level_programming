#include "hash_tables.h"
/**
 * key_index command - gets the index of a key or value pair
 * @key: is the key to access the index
 * @size: this is the size of the hash table array
 * Description: this uses the djb2 algorithim
 *
 * Return: returns the index of the key provided
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
