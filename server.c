#include "minitalk.h"

int main ()
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID : %d", pid);

	return (1);
}