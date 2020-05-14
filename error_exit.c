#include "global.h"
#include "monty.h"

/**
 * error_exit - prints error message and exit
 * with EXIT_FAILURE status.
 *
 * @message1: error message to print part 1.
 * @message2: error message to print part 2.
 */

void error_exit(char *message1, char *message2)
{
	if (message2 == NULL)
		message2 = "";

	fprintf(stderr, "%s", message1);
	fprintf(stderr, "%s\n", message2);
	exit(EXIT_FAILURE);
}
