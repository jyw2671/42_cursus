/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 01:47:13 by yjung             #+#    #+#             */
/*   Updated: 2020/10/14 17:29:32 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;

	if (lst == NULL)
		return (0);
	ret = ft_lstnew((*f)(lst->content));
	if (ret == NULL)
		return (0);
	cur = ret;
	lst = lst->next;
	while (lst)
	{
		if ((cur->next = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (ret);
}
