#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intrep.h"

int main(void)
{
	char buf[100] = {0};

	for (int i = 0; i < 10; i++)
		puts(tobinary(i, buf));
	return EXIT_SUCCESS;
}
