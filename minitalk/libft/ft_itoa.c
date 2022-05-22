/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:03:55 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/11 12:31:17 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_num_str(char *str, int n)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (n / 10)
	{
		str[i] = n % 10 * sign + '0';
		i++;
		n /= 10;
	}
	str[i] = n * sign + '0';
	if (sign < 0)
	{
		i++;
		str[i] = '-';
	}
	str[i + 1] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;
	char	tmp[20];
	char	*res;

	i = 0;
	str = ft_num_str(tmp, n);
	while (str[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (0);
	j = 0;
	while (i-- > 0)
	{
		res[j] = str[i];
		j++;
	}
	res[j] = 0;
	return (res);
}
