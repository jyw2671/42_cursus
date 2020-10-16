/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:07:02 by yjung             #+#    #+#             */
/*   Updated: 2020/10/16 22:07:44 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_sprintf(char *out, const char *format, ...);

#endif
