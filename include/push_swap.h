/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:46:48 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/03 11:37:29 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_syntax(char *str_n); 
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			free_split(char **result_array, int words);
int				count_wd(char const *str, char c);

void			init_stack_a(t_stack_node **a, char **argv);

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

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

void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
