#include "minitalk.h"

int main (int argc, char *argv[])
{
	if (argc != 3 && ft_strlen(argv[2]) != 0)
	{
		ft_printf("Erreur ! Essayer ce format : ./client (pid) (argument)");
		return (0);
	}
	return (1);
}