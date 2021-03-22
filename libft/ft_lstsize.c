/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:47:00 by yjung             #+#    #+#             */
/*   Updated: 2021/03/22 20:38:07 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ret;
	size_t	size;

	size = 0;
	ret = lst;
	while (ret != NULL)
	{
		size++;
		ret = ret->next;
	}
	return (size);
}
