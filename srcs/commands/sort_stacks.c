/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:59:25 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:31:57 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node) //Define uma função que gira os nós do topo de `a` e `b` para o fundo de suas pilhas, se for o movimento mais barato
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //Enquanto o nó atual de `b` não for o nó alvo do nó mais barato de `a`, e o nó atual de `a` não for o nó mais barato
		rr(a, b, FALSE); //Gira os nós de `a` e `b`
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node) //Define uma função que gira os nós do fundo de `a` e `b` para o topo de suas pilhas, se for o movimento mais barato
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //Enquanto o nó atual de `b` não for o nó alvo do nó mais barato de `a` e o nó atual de `a` não for o mais barato
		rrr(a, b, FALSE); //Gira os nós de `a` e `b` reversamente
	current_index(*a); //Atualiza as posições dos nós atuais
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b) //Define uma função que prepara os nós mais baratos no topo das pilhas para empurrar os nós de `a` para a pilha `b`, até que reste três nós em `a`
{
	t_stack_node	*cheapest_node; //Para armazenar o ponteiro para o nó mais barato de `a`

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median) //Se o nó mais barato de `a` e seu nó alvo em `b` estão acima da mediana
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median)) //Se tanto o nó mais barato de `a` quanto o nó alvo em `b` estão abaixo da mediana
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` será executado se nenhum dos nós estiver no topo
	prep_for_push(a, cheapest_node, 'a'); //Garante que o nó mais barato esteja no topo, pronto para ser empurrado
	prep_for_push(b, cheapest_node->target_node, 'b'); //Garante que o nó alvo esteja no topo, pronto para ser empurrado
	pb(b, a, FALSE);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b) //Define uma função que prepara os nós alvo de `b` em `a` para empurrar todos os nós de `b` de volta para a pilha `a`
{
	prep_for_push(a, (*b)->target_node, 'a'); //Garante que o nó alvo de `b` em `a` esteja no topo da pilha
	pa(a, b, FALSE); 
}

static void	min_on_top(t_stack_node **a) //Define uma função que move o menor número para o topo
{
	while ((*a)->nbr != find_min(*a)->nbr) //Enquanto o menor número não estiver no topo
	{
		if (find_min(*a)->above_median) //Gira ou gira reversamente de acordo com a posição do nó em relação à mediana
			ra(a, FALSE);
		else
			rra(a, FALSE);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b) //Define uma função que ordena a pilha `a` se ela tiver mais de 3 nós
{
	int	len_a; //Para armazenar o comprimento da pilha `a`

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a)) //Se a pilha `a` tiver mais de três nós e não estiver ordenada
		pb(b, a, FALSE);
	if (len_a-- > 3 && !stack_sorted(*a)) //Se a pilha `a` ainda tiver mais de três nós e não estiver ordenada
		pb(b, a, FALSE);
	while (len_a-- > 3 && !stack_sorted(*a)) //Se a pilha `a` ainda tiver mais de três nós e não estiver ordenada
	{
		init_nodes_a(*a, *b); //Inicia todos os nós de ambas as pilhas
		move_a_to_b(a, b); //Move os nós mais baratos de `a` para uma pilha `b` ordenada, até restarem três nós em `a`
	}
	sort_three(a);
	while (*b) //Até o final da pilha `b` ser alcançado
	{
		init_nodes_b(*a, *b); //Inicia todos os nós de ambas as pilhas
		move_b_to_a(a, b); //Move todos os nós de `b` de volta para uma pilha `a` ordenada
	}
	current_index(*a); //Atualiza a posição atual da pilha `a`
	min_on_top(a); //Garante que o menor número está no topo
}
