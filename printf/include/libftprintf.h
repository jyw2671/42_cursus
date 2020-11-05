/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/11/05 22:48:24 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_set
{
	long long			val;
	unsigned long long	val_ul;
	unsigned long long	tmp_1;
	unsigned long long	tmp_2;
	unsigned long		ptr_1;
	unsigned long		ptr_2;
	unsigned long		ptr_3;
	int					val_sign;
	int					sign_cnt;
	 // arg로 받은 인수 양수 음수 판별
	int					val_len;
	int					p_len;
// parsing
	int					z_flag;
	int					s_flag;
	int					lefted;
	int					sign;
	int					hash;
	int					ast_p_check; //ast_p 일 때 음수이면 아예 처리 안해주기위해서 판별 구조체
	int					wid;
	int					prec;
	int					prec_com;
	char				*type;
//
	int					cnt;
	int					cmp;
	int					tmp_i;
	char				tmp_c;
	char				*tmp_s;
}						t_set;

int		ft_printf(const char *format, ...);
int		ft_parse_printf(const char **format, t_set *set, va_list ap);
void	ft_parse_lh(const char **format, t_set *set, va_list ap);
void	ft_parse_type(const char **format, t_set *set, va_list ap);
int		ft_check_parse(const char **format, t_set *set, va_list ap);
int		ft_str_zero_check(t_set *set);
void	ft_int_check(const char **format, t_set *set, va_list ap);
void	ft_print_ul(t_set *set, va_list ap);
void	ft_print_l(t_set *set, va_list ap);
void	ft_int_set(t_set *set);
void	ft_int_num(t_set *set);
void	ft_int_print_prec(t_set *set);
void	ft_print_nflag(t_set *set);
void	ft_int_print(t_set *set);
void	ft_int_prec_com(t_set *set);
void	ft_int_prec_cmp(t_set *set);
void	ft_char_set(t_set *set, va_list ap);
void	ft_str_set(t_set *set, va_list ap);
void	ft_hex_set(const char **format, t_set *set, va_list ap);
void	ft_hex_itoa(t_set *set);
void	ft_hash_flag(t_set *set);
void	ft_oct_set(t_set *set, va_list ap);
void	ft_oct_itoa(t_set *set);
void	ft_oct_hash_flag(t_set *set);
void	ft_ptr_set(t_set *set, va_list ap);
void	ft_ptr_itoa(t_set *set);
void	ft_ptr_hash_flag(t_set *set);

#endif
