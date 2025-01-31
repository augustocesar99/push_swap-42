/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:57:14 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:08 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src) //Define uma função que empurra um nó do topo de uma pilha para o topo da outra pilha
{
	t_stack_node	*push_node; //Usado para armazenar o ponteiro para o nó a ser empurrado

	if (!*src) //Verifica se o nó do topo da pilha a ser empurrada existe
		return ;
	push_node = *src; //O nó do topo a ser empurrado é atribuído à variável `t_stack_node`
	*src = (*src)->next; //Move o ponteiro da pilha para o próximo nó, que se tornará o próximo `nó do topo` depois que o nó atual for "removido"
	if (*src) //Verifica se o nó atual existe
		(*src)->prev = NULL; //Define o nó atual como a cabeça da pilha
	push_node->prev = NULL; //Desvincula o nó a ser empurrado da sua pilha
	if (!*dst) //Verifica se a outra pilha está vazia
	{
		*dst = push_node; //Se estiver vazia, atribui como o primeiro nó da pilha o nó que queremos empurrar
		push_node->next = NULL; //Garante que também será o último nó, ou seja, termina corretamente a pilha com NULL
	}
	else //Se a pilha de destino não estiver vazia
	{
		push_node->next = *dst; //Atribui o nó a ser empurrado ao topo do nó atual da pilha
		push_node->next->prev = push_node; //Atribui ao atributo `prev` do "segundo nó", o nó empurrado como o nó atual do topo
		*dst = push_node; //Completa a adição do nó. O ponteiro para o topo da pilha agora aponta para o nó recém-empurrado
	}
}

void	pa(t_stack_node **a, t_stack_node **b, t_bool print)
{
	push(a, b); 
	if (print == FALSE) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, t_bool print)
{
	push(b, a);
	if (print == FALSE)
		ft_printf("pb\n");
}

