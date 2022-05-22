/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:48:08 by eelroy            #+#    #+#             */
/*   Updated: 2021/10/13 14:16:39 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*res;
	t_list	*start;

	if (!lst)
		return (0);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (0);
	start = res;
	lst = lst->next;
	while (lst)
	{
		res->next = ft_lstnew(f(lst->content));
		if (!res->next)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		res = res->next;
		lst = lst->next;
	}
	return (start);
}
