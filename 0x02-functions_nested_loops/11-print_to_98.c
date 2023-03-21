#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - Prints all natural numbers from n to 98
 * Return: Always 0.
 * @n: The number to start printing from
 */

void print_to_98(int n)

{

	if (n >= 0 && n <= 98)
	{
	for (; n <= 98; n++)
	{
	if (n == 98)
	{
	printf("%d, ", n);
	printf("\n");
	break;
	}
	else
	{
	printf("%d, ", n);
	}
	}
	}
	else
	{
	for (; n >= 98; n--)
	{
	if (n == 98)
	{
	printf("%d, ", n);
	printf("\n");
	break;
	}
	else
	{
	printf("%d, ", n);
	}
	}
	}
}
