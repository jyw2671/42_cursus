# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:16:45 by yjung             #+#    #+#              #
#    Updated: 2020/10/18 22:12:06 by yjung            ###   ########.fr        #
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

SRC = ft_printf.c ft_sprintf.c ft_print.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

$(NAME) : $(LIB_FILE) $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -I $(INC_DIR) -I $(LIB_I_DIR) -c $< -o $@

clean : $(LIBFT)_clean
	$(RM) $(OBJ)

fclean : $(LIBFT)_fclean clean
	$(RM) $(NAME)

re: fclean all

$(LIBFT) : $(LIB_FILE)

$(LIB_FILE) :
	make -C $(LIB_DIR)
	@cp $(LIB_FILE) $(NAME)

$(LIBFT)_clean :
	make -C $(LIB_DIR) clean

$(LIBFT)_fclean :
	make  -C $(LIB_DIR) fclean

.PHONY: all clean fclean re $(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean
