/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:11:40 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/14 09:42:23 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	tmp;
	int		res;

	if (!s)
		return (0);
	i = 0;
	res = 0;
	while (s[i] == c && c != 0)
		i++;
	while (s[i])
	{
		tmp = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != tmp)
			res++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (res);
}

static char	*ft_word_create(char const *s, char c, int words, char **res)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
	{
		i = 0;
		while (i < words)
		{
			free (res[i]);
			i++;
		}
		free (res);
		return (0);
	}
	str[i] = 0;
	while (i-- > 0)
		str[i] = s[i];
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_num;
	size_t	i;
	int		j;

	word_num = ft_count(s, c);
	res = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (j < word_num)
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = ft_word_create(s + i, c, j, res);
		if (!res[j])
			return (0);
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	res[j] = 0;
	return (res);
}
