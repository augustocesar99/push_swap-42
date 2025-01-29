/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:31:59 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:28:29 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack_node *stack) //Define uma função que calcula e retorna o comprimento da pilha
{
	int	count; //Para armazenar a contagem de nós

	if (!stack) 
		return (0);
	count = 0;
	while (stack) //Loop até que o final da pilha seja alcançado
	{
		stack = stack->next; //Move para o próximo nó
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack) //Define uma função que retorna o ponteiro para o último nó
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop até que o final da pilha seja alcançado
		stack = stack->next;
	return (stack);
}

t_bool	stack_sorted(t_stack_node *stack) //Define uma função que verifica se a pilha está ordenada em ordem crescente
{
	if (!stack)
		return (TRUE);
	while (stack->next) //Loop até que o final da pilha seja alcançado
	{
		if (stack->nbr > stack->next->nbr) //Verifica se o valor atual é maior que o valor do próximo nó, indicando que está desordenado
			return (FALSE);
		stack = stack->next; //Se não, move para o próximo nó para processamento
	}
	return (TRUE);
}

t_stack_node	*find_min(t_stack_node *stack) //Define uma função que busca na pilha e retorna o nó com o menor número
{
	long			min; //Para armazenar o menor valor até agora
	t_stack_node	*min_node; //Para armazenar um ponteiro que aponta para o menor número

	if (!stack)
		return (NULL);
	min = LONG_MAX; //Atribui ao menor valor até agora o valor máximo de um long integer
	while (stack) //Loop até que o final da pilha seja alcançado
	{
		if (stack->nbr < min) //Verifica se o valor do nó atual é menor que o menor valor até agora
		{
			min = stack->nbr; //Se sim, atualiza o menor número até agora
			min_node = stack; //Define o ponteiro para apontar para o nó com o menor número até agora
		}
		stack = stack->next; //Move para o próximo nó para processamento
	}
	return (min_node); 
}

t_stack_node	*find_max(t_stack_node *stack) //Define uma função que busca na pilha e retorna o nó com o maior número
{
	long			max; //Para armazenar o maior valor até agora
	t_stack_node	*max_node; //Para armazenar um ponteiro que aponta para o maior número

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Atribui ao maior valor até agora o valor mínimo de um long integer
	while (stack) //Loop até que o final da pilha seja alcançado
	{
		if (stack->nbr > max) //Verifica se o valor do nó atual é maior que o maior valor até agora
		{
			max = stack->nbr; //Se sim, atualiza o maior número até agora
			max_node = stack; //Define o ponteiro para apontar para o nó com o maior número até agora
		}
		stack = stack->next; //Move para o próximo nó para processamento
	}
	return (max_node);
}
