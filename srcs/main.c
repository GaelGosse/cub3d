#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void	abc(void)
{
	printf(" world\n");
}

int	main(int argc, char **argv){
	printf("hello\n");
	abc();
	(void)argc;
	(void)argv;
}