# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:16:45 by yjung             #+#    #+#              #
#    Updated: 2020/10/29 04:45:20 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs

OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = ./include

LIBFT = libft.a
LIB_DIR = ./libft
LIB_FILE = $(LIB_DIR)/$(LIBFT)
LIB_I_DIR = $(LIB_DIR)/include

SRC = ft_printf.c ft_parse_printf.c ft_check_parse.c \
	ft_int_set.c ft_int_print.c ft_int_third.c
# ft_type_printf.c

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
	$(CC) $(CFLAG) -I $(LIB_I_DIR) -I $(INC_DIR) -c $< -o $@

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

.PHONY: all clean fclean re $(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean
