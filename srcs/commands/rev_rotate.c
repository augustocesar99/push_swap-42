/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:57:43 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:33:19 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack_node **stack) //Define uma função que gira o nó inferior de uma pilha para o topo
{
	t_stack_node	*last; //Para armazenar o ponteiro para o último nó

	if (!*stack || !(*stack)->next) //Verifica se a pilha está vazia ou se há apenas um nó
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; //Atribui ao atributo `next` do nó antes dele, `NULL`, efetivamente definindo-o como o nó atual da cauda
	last->next = *stack; //Atribui ao seu próprio atributo `next` o nó do topo da pilha
	last->prev = NULL; //Desvincula-se do nó anterior a ele
	*stack = last;  //Completa a adição de si mesmo ao topo da pilha e agora mantém o ponteiro para o nó do topo
	last->next->prev = last; //Atualiza o nó atual da cauda da pilha
}

void	rra(t_stack_node **a, t_bool print) //Gira o fundo de `a` para o topo da pilha e imprime a instrução
{
	rev_rotate(a);
	if (print == FALSE)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, t_bool print) //Gira o fundo de `b` para o topo da pilha e imprime a instrução
{
	rev_rotate(b);
	if (print == FALSE)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, t_bool print) //Gira simultaneamente os nós inferiores de ambas as pilhas para o topo de suas pilhas, diminuindo o custo das instruções
{
	rev_rotate(a);
	rev_rotate(b);
	if (print == FALSE)
		ft_printf("rrr\n");
}
