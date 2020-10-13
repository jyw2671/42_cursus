/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:10:38 by yjung             #+#    #+#             */
/*   Updated: 2020/10/13 23:19:59 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ret;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		ret = ft_lstlast(*lst);
		ret->next = new;
	}
}
