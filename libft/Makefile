# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 18:45:22 by yjung             #+#    #+#              #
#    Updated: 2020/10/13 02:11:27 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h

SRCS = \
	ft_atoi.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_strrchr.c ft_strnstr.c ft_memcpy.c ft_memccpy.c \
	ft_memset.c ft_bzero.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strdup.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_tolower.c ft_toupper.c ft_calloc.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c

BSRCS =

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

bonus: $(BOBJS) $(OBJS)
	ar rc $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
