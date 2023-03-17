#include <stdio.h>

/**
 * main - prints all possible combinations of single digit numbers.
 *
 * Return: 0 on success
 */

int main(void)
{
	int n, d;
	d = 0;

	for (n = '0'; d < 10; n++)
	{
	putchar(n + '0');
	if (n < 9)
	{
	putchar(',');
	putchar(32);
	}
	}
	putchar('\n');
	return (0);
}
