/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:01:42 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 17:43:42 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**a, t_bool print)
{
	swap(a);
	if (print == FALSE)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, t_bool print)
{
	swap(b);
	if (print == FALSE)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, t_bool print)
{
	swap(a);
	swap(b);
	if (print == FALSE)
		ft_printf("ss\n");
}
