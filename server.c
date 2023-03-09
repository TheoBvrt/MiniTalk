/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:50:02 by tbouvera          #+#    #+#             */
/*   Updated: 2023/03/09 11:36:52 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i ++;
	}
}

void	clear_buff(char *buff)
{
	int	i;

	i = 0;
	while (i < 50000)
	{
		buff[i] = '\0';
		i ++;
	}
}

void	read_char(int signal)
{
	static char	buff[50000];
	static int	index;
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit ++;
	if (bit == 8)
	{
		buff[index] = i;
		index ++;
		if (i == '\0')
		{
			print_string(buff);
			write(1, "\n", 1);
			clear_buff(buff);
			index = 0;
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	while (argc == 1)
	{
		signal (SIGUSR1, read_char);
		signal (SIGUSR2, read_char);
		pause();
	}
	return (1);
}
