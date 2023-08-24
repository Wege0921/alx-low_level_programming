#include <stdio.h>

void __attribute__ ((constructor)) pre_main() {
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
