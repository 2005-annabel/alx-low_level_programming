#include <stdio.h>

#include <time.h>

#include <stdio.h>



/**
 * main - Prints a text according number
 * Return: Always (Success)
 *
 */

int main(void)

{

	int n, lastd;

	strand(time(0));
	n = rand() - RAND_MAX /2;
	lastd = n % 10;

	if (lastd > 5)
	{printf("Last digit of %d is %d and is greater than 5\n", n, last
d);
	}
	else if (lastd == 0)
	{
	printf("Last digit of %d is %d and is greater than 0\n", n, lastd);
	}
	else if (lastd < 6 && lastd != 0)
	{
	printf("Last digit of %d is %d and is greater than 0\n"
, n, lastd);
	}
	return (0);

}