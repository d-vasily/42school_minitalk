/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:23:30 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 11:24:47 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (0);
	res[i] = 0;
	while (i-- > 0)
		res[i] = f(i, s[i]);
	return (res);
}
