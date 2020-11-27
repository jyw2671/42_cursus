/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:20:17 by yjung             #+#    #+#             */
/*   Updated: 2020/11/20 02:46:06 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *str);
char				*ft_strnstr(const char *big, const char *little, \
		size_t len);
void				ft_bzero(void *b, size_t n);
void				*ft_memset(void *dst, int c, size_t n);
void				*ft_memchr(const void *ptr, int cmp, size_t n);
void				*ft_memmove(void *dst, const char *src, size_t n);

char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned long long	ft_pow(int b);
int					ft_int_cnt(unsigned long long num);

#endif
