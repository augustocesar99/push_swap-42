/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:46:48 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:37:14 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> //Para usar flags booleanas, por exemplo, para imprimir ou não imprimir
# include <limits.h> //Para definir as macros MIN e MAX
# include "../libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_stack_node //Um contêiner de dados fechado entre chaves {}. `s_` para struct
{
	int					nbr; //O número a ser ordenado
	int					index; //A posição do número na pilha
	int					push_cost; //Quantos comandos no total
	bool				above_median; //Usado para calcular `push_cost`
	bool				cheapest; //O nó que é o mais barato de se fazer os comandos
	struct s_stack_node	*target_node; //O nó alvo de um nó na pilha oposta
	struct s_stack_node	*next; //Um ponteiro para o próximo nó
	struct s_stack_node	*prev; //Um ponteiro para o nó anterior
}	t_stack_node; //O "nome abreviado", "t_stack_node". `t_` para tipo

//***Tratamento de erros
int				error_syntax(char *str_n); 
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

//***Inicialização da pilha
void			init_stack_a(t_stack_node **a, char **argv); //Inicializa a pilha `a` antes de processar
char			**split(char *s, char c); //Para tratar a entrada de números como argumento de string, por exemplo, entre aspas " "

//***Inicialização dos nós
void			init_nodes_a(t_stack_node *a, t_stack_node *b); //Para preparar todos os nós para empurrar `a` para `b`
void			init_nodes_b(t_stack_node *a, t_stack_node *b); //Para preparar todos os nós para empurrar `b` de volta para `a`
void			current_index(t_stack_node *stack); //Define o índice atual do nó
void			set_cheapest(t_stack_node *stack); //Define o nó mais barato da pilha
t_stack_node	*get_cheapest(t_stack_node *stack); //Obtém o nó mais barato de uma pilha
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c); //Prepara os nós necessários no topo para empurrar

//***Funções úteis para pilha
int				stack_len(t_stack_node *stack); //Calcula o comprimento de uma pilha
t_stack_node	*find_last(t_stack_node *stack); //Encontra o último nó de uma pilha
t_bool			stack_sorted(t_stack_node *stack); //Verifica se uma pilha está ordenada
t_stack_node	*find_min(t_stack_node *stack); //Encontra o menor número
t_stack_node	*find_max(t_stack_node *stack); //Encontra o maior número

//***Comandos
void			sa(t_stack_node **a, t_bool print);
void			sb(t_stack_node **b, t_bool print);
void			ss(t_stack_node **a, t_stack_node **b, t_bool print);
void			ra(t_stack_node **a, t_bool print);
void			rb(t_stack_node **b, t_bool print);
void			rr(t_stack_node **a, t_stack_node **b, t_bool print);
void			rra(t_stack_node **a, t_bool print);
void			rrb(t_stack_node **b, t_bool print);
void			rrr(t_stack_node **a, t_stack_node **b, t_bool print);
void			pa(t_stack_node **a, t_stack_node **b, t_bool print);
void			pb(t_stack_node **b, t_stack_node **a, t_bool print);

//***Algoritmo
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b); //Algoritmo de Turk

#endif