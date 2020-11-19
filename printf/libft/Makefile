# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 18:45:22 by yjung             #+#    #+#              #
#    Updated: 2020/11/20 02:43:28 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs

OBJ_DIR = ./object
SRC_DIR = ./src
INC_DIR = ./include

SRC = \
	ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_strnstr.c \
	ft_memset.c ft_bzero.c ft_memmove.c ft_memchr.c ft_substr.c \
	ft_strjoin.c ft_pow.c ft_int_cnt.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(DEBUG) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
