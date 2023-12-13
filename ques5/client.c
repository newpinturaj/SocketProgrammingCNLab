#include <stdio.h>
#include <asm-generic/signal.h>

int	main(int argv, char** argc)
{
	int id = atoi(argc[1]);

	kill(id, SIGUSR1);
	return 0;
}