/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/11/02 21:06:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_set
{
	unsigned int	val;
	int				val_sign;
	int				val_tmp;
	int				sign_cnt;
	 // arg로 받은 인수 양수 음수 판별
	int				val_len;
	int				p_len;
	int				z_flag;
	int				s_flag;
	int				lefted;
	int				sign;
	int				ast_cnt;
	// va_arg값 저장(va_arg는 파일 디스크립터(FD)라 한번 나오는순간 값을 미리 저장해두어야함)
	int				ast_p_check; //ast_p 일 때 음수이면 아예 처리 안해주기위해서 판별 구조체
	unsigned int	wid;
	int				wid_cnt; //int 변형 (size_t i 대신)
	unsigned int	prec;
	int				prec_cnt;
	int				prec_com;
	int				cnt;
	int				cmp;
	int				tmp_i;
	unsigned int	tmp_u;
	long long int	tmp_l;
	char			tmp_c;
	char			*tmp_s;
}					t_set;

int		ft_printf(const char *format, ...);
int		ft_parse_printf(const char **format, t_set *set, va_list ap);
int		ft_check_parse(const char **format, t_set *set, va_list ap);
int		ft_str_zero_check(t_set *set);
void	ft_int_check(const char **format, t_set *set, va_list ap);
void	ft_int_set(t_set *set);
void	ft_int_num(t_set *set);
void	ft_int_prec(t_set *set);
void	ft_int_print_prec(t_set *set);
void	ft_print_nflag(t_set *set);
void	ft_int_print(t_set *set);
void	print_sturct(t_set *set);
void	ft_char_set(t_set *set, va_list ap);
void	ft_str_set(t_set *set, va_list ap);

#endif
