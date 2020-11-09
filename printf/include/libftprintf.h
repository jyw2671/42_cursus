/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/11/09 22:11:13 by yjung            ###   ########.fr       */
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
	double				tmp_d;
	unsigned long long	tmp_1;
	unsigned long long	tmp_2;
	unsigned long		ptr_1;
	unsigned long		ptr_2;
	unsigned long		ptr_3;
	int					len;
	int					val_sign;
	int					sign_cnt;
	int					val_len;
	int					p_len;
// parsing
	int					z_flag;
	int					s_flag;
	int					lefted;
	int					sign;
	int					hash;
	int					ast_p_check;
	int					wid;
	int					prec;
	int					prec_com;
	int					type_l;
	int					type_h;
	int					cnt;
	int					cmp;
	int					tmp_i;
	char				tmp_c;
	char				*tmp_s;
}						t_set;

typedef struct			s_num
{
	union
	{
		double			d_val;
		struct
		{
			size_t		frac : 52;
			size_t		exp : 11;
			size_t		sign : 1;
		};
	};
}						t_num;

int						ft_printf(const char *format, ...);
int						ft_parse_printf(const char **format, t_set *set, va_list ap);
void					ft_parse_ex_type(const char **format, t_set *set, va_list ap);
void					ft_parse_type(const char **format, t_set *set, va_list ap);
int						ft_check_parse(const char **format, t_set *set, va_list ap);
int						ft_str_zero_check(t_set *set);
void					ft_int_check(const char **format, t_set *set, va_list ap);
void					ft_print_ul(t_set *set, va_list ap);
void					ft_print_l(t_set *set, va_list ap);
void					ft_int_set(t_set *set);
void					ft_int_num(t_set *set);
void					ft_int_print_prec(t_set *set);
void					ft_print_nflag(t_set *set);
void					ft_int_print(t_set *set);
void					ft_int_prec_com(t_set *set);
void					ft_int_prec_cmp(t_set *set);
void					ft_char_set(t_set *set, va_list ap);
void					ft_str_set(t_set *set, va_list ap);
void					ft_hex_set(const char **format, t_set *set, va_list ap);
void					ft_hex_itoa(t_set *set);
void					ft_hash_flag(t_set *set);
void					ft_oct_set(t_set *set, va_list ap);
void					ft_oct_itoa(t_set *set);
void					ft_oct_hash_flag(t_set *set);
void					ft_ptr_set(t_set *set, va_list ap);
void					ft_ptr_itoa(t_set *set);
void					ft_ptr_hash_flag(t_set *set);
void					ft_float_set(t_set *set, va_list ap);

#endif
