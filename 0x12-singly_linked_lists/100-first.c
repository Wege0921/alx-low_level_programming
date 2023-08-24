#include <stdio.h>
/**
 * pre_main - Function executed before the main function.
 *
 * Description: This function is executed automatically before the main
 * function is called. It prints a predefined message.
 */

void __attribute__ ((constructor)) pre_main() {
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
