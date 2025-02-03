# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:41:52 by acesar-m          #+#    #+#              #
#    Updated: 2025/02/03 16:45:26 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Padrão
NAME				= push_swap

# Diretórios
LIBFT				= ./libft/libft.a
INC					= include/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compilador e CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I$(INC)
RM					= rm -f

# Arquivos Fonte
COMMANDS_SRCS		= $(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_SRCS		= $(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/init_a_to_b.c \
						$(SRC_DIR)push_swap/init_b_to_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/stack_utils.c

# Concatenar todos os arquivos fonte
SRCS 				= $(COMMANDS_SRCS) $(PUSH_SWAP_SRCS)

# Gerar os arquivos objeto a partir dos arquivos fonte
OBJ 				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Regras de construção
all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@printf "\033[0;32mCompilation completed successfully!\033[0m\n"

$(LIBFT):
					@make -s -C ./libft

# Compilar arquivos objeto a partir dos arquivos fonte
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -s -C ./libft

fclean: clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@printf "\033[0;33mFiles removed successfully!\033[0m\n"

re: fclean all

# Alvos phony representam ações, não arquivos
.PHONY: all clean fclean re