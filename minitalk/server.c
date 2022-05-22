/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:39:52 by eelroy            #+#    #+#             */
/*   Updated: 2022/03/06 16:48:18 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_error(void)
{
	ft_putstr_fd("ERROR: The signal hasn't been sent!", 1);
	exit (-1);
}

static void	close_server(int sig)
{
	(void)sig;
	ft_putstr_fd("\nServer has been closed.\n", 1);
	exit (0);
}

static void	get_msg(int sig, siginfo_t *info, void *context)
{
	static int	bits_received;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bits_received);
	if (++bits_received == 8 && c != 0)
	{
		write(1, &c, 1);
		c = 0;
		bits_received = 0;
	}
	else if (bits_received == 8 && c == 0)
	{
		bits_received = 0;
		if (kill(info->si_pid, SIGUSR1))
			ft_error();
		write(1, "\n", 1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	if (sigemptyset(&mask) == -1
		|| sigaddset(&mask, SIGUSR1) == -1
		|| sigaddset(&mask, SIGUSR2) == -1)
		exit (-1);
	sa.sa_mask = mask;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_msg;
	signal(SIGINT, close_server);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit (-1);
	ft_putstr_fd("\nPID:  ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
