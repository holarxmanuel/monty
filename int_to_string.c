#include <stdlib.h>
#include "monty.h"

/**
 * _abs - Computes the absolute value of an integer.
 * @i: The integer to compute the absolute value of.
 *
 * Return: The absolute value of the input integer.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * fill_numbase_buff - Fills a buffer with a number converted to a given base.
 * @num: The number to convert to a string in the specified base.
 * @base: The base of the number representation used.
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * Return: None (void).
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87; /* ASCII values a, b, c, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * get_int - Converts an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A newly allocated string containing the converted integer.
 *         NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* Add space for negative sign */
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * get_numbase_len - Computes the length needed for a number in a given base.
 * @num: The number to compute the length for.
 * @base: The base of the number representation used.
 *
 * Return: The length needed for the number in the specified base.
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
