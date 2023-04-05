#include "main.h"
/**
 * _puts_recursion - function like puts();
 * @s: pointer to string.
 *
 * Return: Always 0(Success)
 */
void _puts_recursion(char *s)
{
	if (*s == '\0') /* base case */
	{
		 _putchar('\n');
		 return;
	}
		_putchar(*s);
		_puts_recursion(s + 1);
}
