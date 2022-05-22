/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:30:32 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 11:04:45 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_instr(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_instr(s1[start], set) && s1[start])
		start++;
	while (end >= start && ft_instr(s1[end], set))
		end--;
	if (end < start)
		s = (char *)malloc(1);
	else
		s = (char *)malloc(sizeof(char) * (end - start + 1) + 1);
	if (!s)
		return (0);
	s[end - start + 1] = 0;
	while (start <= end)
	{
		s[end - start] = s1[end];
		end--;
	}
	return (s);
}
