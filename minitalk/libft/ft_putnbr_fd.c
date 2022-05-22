/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:46:12 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 11:33:07 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		i;
	char	tmp[20];

	sign = 1;
	if (n < 0)
		sign = -1;
	if (sign == -1)
		write (fd, "-", 1);
	i = 0;
	while (n / 10)
	{
		tmp[i] = n % 10 * sign + '0';
		n /= 10;
		i++;
	}
	tmp[i] = n * sign + '0';
	while (i >= 0)
	{
		write(fd, &tmp[i], 1);
		i--;
	}
}
