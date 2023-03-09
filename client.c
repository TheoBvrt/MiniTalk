/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:50:02 by tbouvera          #+#    #+#             */
/*   Updated: 2023/03/09 11:34:59 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	unsigned char	bit;
	unsigned char	mask;

	bit = 0;
	while (bit < 8)
	{
		mask = (unsigned char)1 << bit;
		if (c & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3 && ft_strlen(argv[2]) != 0)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(pid, argv[2][i]);
			i ++;
		}
		send_char (pid, '\0');
	}
	else
	{
		ft_printf("Erreur ! Essayer ce format : ./client <PID> <Message>");
		return (0);
	}
	return (1);
}
