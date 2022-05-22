/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:12:10 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 10:24:10 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = 0;
	while (s1[i])
		i++;
	res = (char *) malloc(sizeof(char) * i + 1);
	if (!res)
		return (0);
	res[i] = 0;
	while (i > 0)
	{
		i--;
		res[i] = s1[i];
	}
	return (res);
}
