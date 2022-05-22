/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:13 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 15:00:20 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	res;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	res = len_src + len_dst;
	if (len_dst > dstsize)
		res = len_src + dstsize;
	i = 0;
	while (i + len_dst + 1 < dstsize && src[i])
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	if (i > 0)
		dst[i + len_dst] = 0;
	return (res);
}
