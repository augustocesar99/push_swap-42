/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:57 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:31:22 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a) //Define uma função que lida quando a pilha `a` tem três nós e a ordena
{
	t_stack_node	*biggest_node; //Para armazenar um ponteiro para o maior nó da pilha `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Verifica se o nó atual é o maior
		ra(a, FALSE); //Se for, gira o nó do topo para o fundo da pilha
	else if ((*a)->next == biggest_node) //Verifica se o segundo nó é o maior
		rra(a, FALSE); //Se for, gira reversamente o nó do fundo para o topo da pilha
	if ((*a)->nbr > (*a)->next->nbr) //Verifica se o nó do fundo é o maior, mas o nó do topo é maior que o segundo nó
		sa(a, FALSE); //Se for, simplesmente troca o nó do topo com o segundo nó
}
