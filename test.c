#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>
#include <time.h>

int	main(int argc, char **argv, char **envp){
	char *str;

	str = malloc(8);
	str = "abcdefg\0";
	printf("%s\n", str);

	// free(str);
	(void)argc;
	(void)argv;
	(void)envp;
}