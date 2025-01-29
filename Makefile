# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 16:35:05 by acesar-m          #+#    #+#              #
#    Updated: 2025/01/29 16:35:06 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Padrão
NAME				= push_swap

# Diretórios
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compilador e CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Arquivos Fonte
COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/init_a_to_b.c \
						$(SRC_DIR)push_swap/init_b_to_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/stack_utils.c

# Concatenar todos os arquivos fonte
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Aplica a substituição de padrões para cada arquivo fonte em SRC e gera uma lista correspondente de arquivos objeto no OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Regras de construção
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compilar arquivos objeto a partir dos arquivos fonte
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Alvos phony representam ações, não arquivos
.PHONY: 			start all clean fclean re
