#include <stdio.h>
#include "main.h"

/**
 * set_string - This fuctions sets the value of a pointer to a char.
 * @s: Double pointer to a string.
 * @to: Pointer to the string to be set.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
