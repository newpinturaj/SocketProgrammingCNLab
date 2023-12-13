#include <stdio.h>
#include <asm-generic/signal.h>

void	handle_user_sig(int sig)
{
	write(1, "printsomethingr", 14);
}

int	main(void)
{
	int pid = getpid();

	printf("%d\n", pid);
	pause();
	struct sigaction sa = { 0 };
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_user_sig;
	sigaction(SIGUSR1, &sa, NULL);
	return (0);
}