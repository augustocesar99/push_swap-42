/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:01:42 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:31:04 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **head) //Define uma função que troca as posições do nó do topo e do segundo nó de uma pilha
{
	if (!*head || !(*head)->next) //Verifica se o nó do topo, ou o segundo nó da pilha existe
		return ;
	*head = (*head)->next; //Atualiza o `head` para apontar para o próximo nó, efetivamente trocando o primeiro e o segundo nós
	(*head)->prev->prev = *head; //Atualiza o ponteiro `prev` do nó antes do `novo head` para apontar para o `novo head`
	(*head)->prev->next = (*head)->next; //Atualiza o ponteiro `next` do nó antes do `novo head` para pular o `antigo head` e apontar diretamente para o `novo head`
	if ((*head)->next) //Verifica se há um nó `next` após o `novo head` e
		(*head)->next->prev = (*head)->prev; //Se sim, atualiza o ponteiro `prev` para apontar de volta para o `novo head`
	(*head)->next = (*head)->prev; //Atualiza o ponteiro `next` do `novo head` para apontar para o `antigo head`, efetivamente trocando suas posições
	(*head)->prev = NULL; //Define o ponteiro `prev` do `novo head` como `NULL`, completando a troca
}

void	sa(t_stack_node	**a, t_bool print) //Troca os dois primeiros nós da pilha `a` e imprime a instrução
{
	swap(a);
	if (print == FALSE)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, t_bool print) //Troca os dois primeiros nós da pilha `b` e imprime a instrução
{
	swap(b);
	if (print == FALSE)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, t_bool print) //Troca simultaneamente os dois primeiros nós de ambas as pilhas e imprime a instrução
{
	swap(a);
	swap(b);
	if (print == FALSE)
		ft_printf("ss\n");
}
