/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:01:33 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/11 12:27:20 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	i;
	void			*x;

	i = 0;
	x = malloc(count * size);
	if (!x)
		return (0);
	while (i < size * count)
	{
		((char *) x)[i] = 0;
		i++;
	}
	return (x);
}
