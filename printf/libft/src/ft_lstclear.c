/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:39:50 by yjung             #+#    #+#             */
/*   Updated: 2020/10/14 01:08:11 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ret;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		ret = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ret;
	}
	*lst = 0;
}
