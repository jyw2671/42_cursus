# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:16:45 by yjung             #+#    #+#              #
#    Updated: 2020/11/20 20:08:29 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs

OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = ./includes

LIBFT = libft.a
LIB_DIR = ./libft
LIB_FILE = $(LIB_DIR)/$(LIBFT)
LIB_I_DIR = $(LIB_DIR)/includes

SRC = ft_printf.c ft_parse_printf.c ft_check_parse.c ft_parse_type.c \
	ft_int_set.c ft_int_print.c ft_int_check.c \
	ft_char_set.c ft_str_set.c ft_str_zero_check.c \
	ft_hex_set.c ft_hex_print.c \
	ft_ptr_set.c ft_ptr_print.c \
	ft_oct_set.c ft_oct_print.c \
	ft_float_set.c ft_float_print.c ft_float_z_print.c \
	ft_e_set.c ft_e_print.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

$(NAME) : $(LIB_FILE) $(OBJ_DIR) $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(LIB_FILE) :
	make -C $(LIB_DIR)
	@cp $(LIB_FILE) $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(DEBUG) $(CFLAG) -I $(LIB_I_DIR) -I $(INC_DIR) -c $< -o $@

bonus : $(NAME)

clean : $(LIBFT)_clean
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ)
	rm -rf $(OBJ_DIR)

fclean : $(LIBFT)_fclean clean
	$(RM) $(NAME)

re: fclean all

$(LIBFT) : $(LIB_FILE)

$(LIBFT)_clean :
	make -C $(LIB_DIR) clean

$(LIBFT)_fclean :
	make -C $(LIB_DIR) fclean

.PHONY: all clean fclean bonus re $(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean
