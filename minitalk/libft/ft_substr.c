/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:40:11 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 10:33:52 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*s1;

	if (!s)
		return (0);
	i = 0;
	len_s = 0;
	while (s[len_s])
		len_s++;
	while (i < len && i + (size_t)start < len_s)
		i++;
	s1 = (char *)malloc(sizeof(char) * i + 1);
	if (!s1)
		return (0);
	s1[i] = 0;
	while (i-- > 0)
		s1[i] = s[start + i];
	return (s1);
}
