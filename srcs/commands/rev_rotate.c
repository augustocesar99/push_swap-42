/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:57:43 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 17:41:51 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, t_bool print)
{
	rev_rotate(a);
	if (print == FALSE)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, t_bool print)
{
	rev_rotate(b);
	if (print == FALSE)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print == FALSE)
		ft_printf("rrr\n");
}
