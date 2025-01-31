/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:32:08 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:46 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static long	ft_atol(const char *s) //Define uma função que converte uma string em um valor long
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n) //Define uma função que busca o último nó para anexar à lista encadeada
{
	t_stack_node	*node; //Para armazenar um ponteiro para o novo nó a ser criado com o valor `n`
	t_stack_node	*last_node; //Para armazenar um ponteiro para o atual último nó da pilha

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); //Aloca memória para o novo nó
	if (!node)
		return ;
	node->next = NULL; //Define o ponteiro 'next' do novo nó como NULL, pois será o último nó da lista
	node->nbr = n; //Define o valor `nbr` do novo nó como `n`
	node->cheapest = 0; // Inicializa o campo 'cheapest' como 0;
	// Outros elementos na estrutura poderiam ser inicializados também, mas por enquanto, este foi o único que estava causando um problema no Valgrind
	if (!(*stack)) //Verifica se a pilha está vazia ou apontando para NULL, indicando que é necessário encontrar o primeiro nó
	{
		*stack = node; //Se estiver vazia, atualiza o ponteiro *stack para apontar para o nó, tornando-o o novo início da lista encadeada
		node->prev = NULL; //Define o ponteiro 'prev' do nó inicial como NULL, pois é o primeiro nó
	}
	else //Se a pilha não estiver vazia, significa que já existem nós na lista encadeada
	{
		last_node = find_last(*stack); //Neste caso, encontra o último nó
		last_node->next = node; //Anexa o novo nó ao último nó
		node->prev = last_node; //Atualiza o ponteiro 'prev' do novo nó e conclui a anexação
	}
}

void	init_stack_a(t_stack_node **a, char **argv) //Define uma função que inicializa a pilha `a`, tratando possíveis erros e anexando os nós necessários para completar a pilha
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Verifica se houve overflow
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a); 
		append_node(a, (int)n); //Se não houver erros, anexa o nó à lista encadeada, criando um novo nó e atribuindo `n` a ele
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack) //Define uma função que busca o nó mais barato, que é marcado pelo valor booleano
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name) //Define uma função que move o nó desejado para o topo da pilha
{
	while (*stack != top_node) //Verifica se o nó desejado já não é o primeiro da pilha
	{
		if (stack_name == 'a') //Se não for, e for a pilha `a`, executa o seguinte
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //Se não for, e for a pilha `b`, executa o seguinte
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}
