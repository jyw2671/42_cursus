/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/10/28 06:23:30 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_set
{
	unsigned int	val;
	int				val_sign;
	int				val_tmp;
	 // arg로 받은 인수 양수 음수 판별
	int				val_len;
	int				p_len;
	int				z_flag;
	int				s_flag;
	int				lefted;
	int				sign;
	int				ast_cnt;
	unsigned int	ast_w_val; //ast값 임시 저장
	// va_arg값 저장(va_arg는 파일 디스크립터(FD)라 한번 나오는순간 값을 미리 저장해두어야함)
	int				ast_p_check; //ast_p 일 때 음수이면 아예 처리 안해주기위해서 판별 구조체
	unsigned int	ast_p_val;
	unsigned int	wid;
	int				wid_cnt; //int 변형 (size_t i 대신)
	unsigned int	prec;
	int				prec_cnt;
	char			type;
	int				tmp_i;
	char			tmp_c;
}					t_set;

int		ft_printf(const char *format, ...);
int		ft_parse_printf(const char **format, t_set *set, va_list ap);
void	ft_type_printf(t_set *set, va_list ap);
int		ft_check_parse(const char **format, t_set *set, va_list ap);
void	ft_int_set(t_set *set, va_list ap);
void	ft_int_print(t_set *set);

#endif
