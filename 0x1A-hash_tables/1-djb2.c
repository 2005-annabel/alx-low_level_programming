#include "hash_tables.h"
/**
 * hash_djb2 command - is for implementation of djb2 algorithm
 * @str: the string is used to generate the hash value
 *
 * Return: the new hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	/* initiating the array */
	unsigned long int hash;
	int c;
	/* value assigning */
	hash = 5381;
	/* checking the value */
	while ((c = *str++))
		/* hash value */
		hash = ((hash << 5) + hash) +c;
	return (hash);
}
