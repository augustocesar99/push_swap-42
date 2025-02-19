# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:41:52 by acesar-m          #+#    #+#              #
#    Updated: 2025/02/19 12:44:36 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

LIBFT				= ./libft/libft.a
INC					= include/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I$(INC)
RM					= rm -f

INSTRUCTIONS_SRCS		= $(SRC_DIR)instructions/push.c \
						$(SRC_DIR)instructions/rev_rotate.c \
						$(SRC_DIR)instructions/rotate.c \
						$(SRC_DIR)instructions/sort_stacks.c \
						$(SRC_DIR)instructions/sort_stacks_utils.c \
						$(SRC_DIR)instructions/sort_three.c \
						$(SRC_DIR)instructions/swap.c

PUSH_SWAP_SRCS		= $(SRC_DIR)push_swap/errors.c \
						$(SRC_DIR)push_swap/a_to_b.c \
						$(SRC_DIR)push_swap/b_to_a.c \
						$(SRC_DIR)push_swap/main.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/stack_utils.c

SRCS 				= $(INSTRUCTIONS_SRCS) $(PUSH_SWAP_SRCS)

OBJ 				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@printf "\033[0;32mCompilation completed successfully!\033[0m\n"

$(LIBFT):
					@make -s -C ./libft

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -s -C ./libft

fclean: clean
					@$(RM) $(NAME)
					@printf "\033[0;33mFiles removed successfully!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re