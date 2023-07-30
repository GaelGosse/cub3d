# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

float	rounded(float flt)
{
	float	tmp;

	tmp = flt * 10000000;
	// while (tmp > 0)
	// {

	// }
	printf("floor(flt): %f\n", floorf(flt));
	printf("\n");
	printf("     (flt): %f""\n", flt);
	printf("round(flt): %f\n", roundf(flt));
	printf("\n");
	printf(" ceil(flt): %f\n", ceilf(flt));
	// printf("           flt = %f""\n", flt );
	// printf("      flt * 10 = %f""\n", flt * 10);
	// printf("     flt * 100 = %f""\n", flt * 100);
	// printf("    flt * 1000 = %f""\n", flt * 1000);
	// printf("   flt * 10000 = %f""\n", flt * 10000);
	// printf("  flt * 100000 = %f""\n", flt * 100000);
	// printf(" flt * 1000000 = %f""\n", flt * 1000000);
	// printf("flt * 10000000 = %f""\n", flt * 10000000);
	return (0);
	(void)tmp;
}

int	main(int argc, char **argv, char **envp){
	char	*str;
	int		nbr;
	float	flt;

	str = "abcde";
	nbr = 8;
	flt = 1.506;
	printf("\n");
	// 134.071579
	// 135.992737
	rounded(192.575229);
	printf("\n");
	(void)str;
	(void)nbr;
	(void)flt;
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}