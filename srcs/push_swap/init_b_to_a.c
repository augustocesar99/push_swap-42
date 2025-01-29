/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:14:07 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 14:14:08 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b) //Define uma função que define para o nó atual de `a`, seu nó de destino da pilha `b`
{
	t_stack_node	*current_a; //Para armazenar o ponteiro para o nó atual de `a`
	t_stack_node	*target_node; //Para armazenar o ponteiro do nó de destino para o nó de `b`
	long			best_match_index; //Para armazenar o "número maior mais próximo" até o momento

	while (b)
	{
		best_match_index = LONG_MAX; //Define a melhor correspondência atual como o valor máximo de long
		current_a = a; //Atribui ao ponteiro para apontar para o nó atual de `a`
		while (current_a) //Enquanto o ponteiro não for NULL
		{
			if (current_a->nbr > b->nbr 
				&& current_a->nbr < best_match_index) //Verifica se o valor do nó `a` é maior que o nó `b`, && menor que o "número maior mais próximo" até o momento
			{
				best_match_index = current_a->nbr; //Define a melhor correspondência como o valor no nó atual de `a`
				target_node = current_a; //Define o ponteiro do nó de destino de `b` para apontar para o nó atual de `a`
			}
			current_a = current_a->next; //Move para o próximo nó de `a` para processar
		}
		if (best_match_index == LONG_MAX) //Se o valor da melhor correspondência não foi alterado
			b->target_node = find_min(a); //Define o ponteiro do nó de destino de `b` para apontar para o menor número da pilha `a`
		else
			b->target_node = target_node; //Se o valor da melhor correspondência foi atualizado, então temos um nó de destino para o nó atual de `b`
		b = b->next; //Move para o próximo nó de `b` para processar
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b) //Define uma função que prepara os nós para empurrar `b` para `a`
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
