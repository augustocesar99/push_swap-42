/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:58:31 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:16 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack_node **stack) //Define uma função que gira o nó do topo da pilha para o fundo da pilha
{
	t_stack_node	*last_node; //Para armazenar um ponteiro para o último nó da pilha

	if (!*stack || !(*stack)->next) //Verifica se a pilha está vazia ou se há apenas um nó
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; //Atribui ao último nó, o atributo `next` como o nó do topo, efetivamente colocando o nó atual do topo como o último nó
	*stack = (*stack)->next; //Atribui ao ponteiro do topo da pilha, o nó depois dele (o segundo a partir do topo)
	(*stack)->prev = NULL; //Completa a definição do nó atual do topo, desvinculando-o do nó anterior ao topo
	last_node->next->prev = last_node; //Reconecta o ponteiro `prev` do segundo nó para apontar para o que antes era o último nó da pilha
	last_node->next->next = NULL; //Atribui ao atributo `next` do nó atual da cauda, `NULL`, efetivamente definindo-o como o nó atual da cauda e finalizando corretamente a pilha com NULL
}		

void	ra(t_stack_node **a, t_bool print) //Gira o nó do topo de `a` para o fundo da pilha e imprime a instrução
{
	rotate(a);
	if (print == FALSE)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, t_bool print) //Gira o nó do topo de `b` para o fundo da pilha e imprime a instrução
{
	rotate(b);
	if (print == FALSE)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, t_bool print) //Gira simultaneamente os nós do topo de `a` e `b` para o fundo da pilha e imprime a instrução
{
	rotate(a);
	rotate(b);
	if (print == FALSE)
		ft_printf("rr\n");
}
