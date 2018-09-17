# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshata <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 10:57:57 by tshata            #+#    #+#              #
#    Updated: 2018/09/17 17:49:27 by tshata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Executable
NAME = ../checker

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

# Sources
SRC_NAME = checker.c\
		   rotate_functs.c\
		   validation_functs.c\
		   push_functs.c\
		   swap_functs.c\
		   work.c\
		   read_nbrs_ext.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

LDFLAGS += -L ../libft -lft
CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror -I. -g

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	@make -C ../libft/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	@echo "\033[33mRemoval of .o files of libft objects ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31m .o  deleted\n\033[0m"

cleanlib:
	@make clean -C ../libft/

fclean: clean fcleanlib
	@echo "033[33mRemoval of libft...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mlibft.a removed\n\033[0m"

fcleanlib:
	@make fclean -C ../libft/

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re
