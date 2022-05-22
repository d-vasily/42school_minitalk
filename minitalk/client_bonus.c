/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:18:47 by eelroy            #+#    #+#             */
/*   Updated: 2022/03/06 16:47:23 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	message_received(int sig)
{
	(void)sig;
	ft_putstr_fd("Message received\n", 1);
	exit (0);
}

static void	send_char(int pid, char c)
{
	int	kill_res;
	int	bits_sent;

	bits_sent = 0;
	while (bits_sent < 8)
	{
		if (c & (1 << bits_sent))
			kill_res = kill(pid, SIGUSR1);
		else
			kill_res = kill(pid, SIGUSR2);
		if (kill_res || usleep(100))
		{
			ft_putstr_fd("ERROR: The signal hasn't been sent!", 1);
			exit (-1);
		}
		bits_sent++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("ERORR: Incorrect number of arguments!\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, message_received);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		argv[2]++;
	}
	send_char(pid, 0);
	while (1)
		pause ();
	return (0);
}
