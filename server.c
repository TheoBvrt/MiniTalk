#include "minitalk.h"

void read_char(int signal)
{
	static int bit;
	static int i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit ++;
	ft_printf("Test");
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main (int argc, char ** argv)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID : %d", pid);
	while (argc == 1)
	{
		signal (SIGUSR1, read_char);
		signal (SIGUSR2, read_char);
		pause();
	}
	return (1);
}