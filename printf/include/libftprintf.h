/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/10/26 22:32:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_set
{
	int			z_flag;
	int			s_flag;
	int			lefted;
	int			sign;
	int			ptr_w;
	int			ptr_w_val;
	// va_arg값 저장(va_arg는 파일 디스크립터(FD)라 한번 나오는순간 값을 미리 저장해두어야함)
	int			ptr_p;
	int			ptr_p_check;
	int			ptr_p_val;
	int			wid;
	int			wid_cnt; //int 변형 (size_t i 대신)
	int			prec;
	int			prec_cnt;
	char		type;
}				t_set;

int		ft_printf(const char *format, ...);
int		ft_parse_printf(char **format, t_set *set, va_list ap);
void	ft_type_printf(t_set *set, va_list ap);
int		ft_check_parse(char **format, t_set *set, va_list ap);
void	ft_int_set(t_set *set, va_list ap);
int		ft_sprintf(char *out, const char *format, ...);

#endif
