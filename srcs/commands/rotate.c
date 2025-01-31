/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:58:31 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 17:42:13 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}		

void	ra(t_stack_node **a, t_bool print)
{
	rotate(a);
	if (print == FALSE)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, t_bool print)
{
	rotate(b);
	if (print == FALSE)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	rotate(a);
	rotate(b);
	if (print == FALSE)
		ft_printf("rr\n");
}
