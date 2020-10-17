# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:16:45 by yjung             #+#    #+#              #
#    Updated: 2020/10/18 02:56:45 by yjung            ###   ########.fr        #
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

LIB_O_DIR = ./libft/obj
LIB_S_DIR = ./libft/src
LIB_I_DIR = ./libft/include

SRC =

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
LIB_OBJ = $(addprefix $(LIB_O_DIR)/, $(notdir $(LIB_SRC:.c=.o)))

all : $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	$(AR) $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(LIB_O_DIR)
	$(CC) $(CFLAG) -I $(INC_DIR) -I $(LIB_I_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ) $(LIB_OBJ)

fclean: clean
	$(RM) $(NAME)
	@ranlib $(NAME)

re: fclean all

.PHONY: all clean fclean re
