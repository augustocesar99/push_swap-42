/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:12:49 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:34 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i; //Para armazenar o índice do nó atual
	int	median; //Para armazenar a posição da mediana da pilha

	i = 0; //O primeiro índice é `0`
	if (!stack) //Verifica se a pilha está vazia
		return ;
	median = stack_len(stack) / 2; //Calcula a mediana dividindo o tamanho da pilha por 2
	while (stack) //Percorre todos os nós até que o final da pilha seja alcançado
	{
		stack->index = i; //Atribui o valor do índice atual ao nó atual
		if (i <= median) //Verifica se o nó atual está acima ou abaixo da mediana
			stack->above_median = TRUE; //Se estiver acima, define o dado `above_median` do nó como verdadeiro
		else
			stack->above_median = FALSE; //Se estiver abaixo, define o dado `above_median` do nó como falso
		stack = stack->next; //Move para o próximo nó para atribuir o índice
		++i; //Incrementa o valor do índice para definir o próximo nó
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b) //Encontra o nó de destino de `a` na pilha `b`
{
	t_stack_node	*current_b; //Para armazenar o ponteiro para o nó atual na pilha `b` e iterar através de cada nó seguinte
	t_stack_node	*target_node; //Para armazenar o ponteiro para o nó de destino na pilha `b`
	long			best_match_index; //Neste caso, o índice da melhor correspondência armazena o valor do "número menor mais próximo" até o momento

	while (a) //Enquanto houver nós na pilha `a`
	{
		best_match_index = LONG_MIN; //Atribui o menor `long` como o número menor mais próximo até o momento
		current_b = b; //Atribui ao `current_b` o nó atual de `b`
		while (current_b) //Busca iterativamente por todos os nós na pilha `b` até que o final da pilha seja alcançado
		{
			if (current_b->nbr < a->nbr 
				&& current_b->nbr > best_match_index) //Verifica se o nó de `b` é menor que o nó de `a` e maior que o número menor mais próximo até o momento
			{
				best_match_index = current_b->nbr; //Se sim, atualiza o valor do número menor mais próximo
				target_node = current_b; //Atribui o nó atual de `b` como o nó de destino
			}
			current_b = current_b->next; //Move para o próximo nó de `b` para comparação, até encontrar um "número menor mais próximo"
		}
		if (best_match_index == LONG_MIN) //Verifica se o `LONG_MIN` não foi alterado, significa que não encontramos nada menor
			a->target_node = find_max(b); //Se não, encontra o maior valor de `b` e define isso como o nó de destino
		else
			a->target_node = target_node; //Se uma "melhor correspondência" foi encontrada, define o nó de destino como o nó correspondente
		a = a->next; //Move para o próximo nó de `a` para encontrar seu nó de destino em `b`
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define uma função que analisa o custo do nó de `a` junto com seu nó de destino em `b`, que é a soma do número de instruções para ambos os nós se moverem para o topo de suas pilhas
{
	int	len_a; //Para armazenar o tamanho da pilha `a`
	int	len_b; //Para armazenar o tamanho da pilha `b`

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) //Percorre cada nó até que o final da pilha seja alcançado
	{
		a->push_cost = a->index; //Atribui o custo de movimento do nó de `a`, seu valor de índice
		if (!(a->above_median)) //Verifica se o dado `above_median` é falso, significando que está abaixo da mediana
			a->push_cost = len_a - (a->index); //Se sim, atualiza o custo de movimento do nó de `a` para o tamanho da pilha - índice
		if (a->target_node->above_median) //Verifica se o nó de destino de `a` em `b` tem o atributo `above_median` como "verdadeiro", significando que o nó de destino de `b` está acima da mediana
			a->push_cost += a->target_node->index; //Se sim, atualiza o custo de movimento de `a`, a soma de (seu índice atual) + (índice do nó de destino de `b`)
		else //Se o nó de `a` está acima da mediana e o nó de destino de `b` está abaixo da mediana
			a->push_cost += len_b - (a->target_node->index); //Atualiza o custo de movimento de `a`, a soma de (seu índice atual) + (tamanho da pilha `b` - índice do nó de destino de `b`)
		a = a->next; //Move para o próximo nó de `a` para a análise de custo
	}
}

void	set_cheapest(t_stack_node *stack) //Define uma função que define o atributo `cheapest` de um nó como `verdadeiro` ou `falso`
{
	long			cheapest_value; //Para armazenar o valor do nó mais barato até o momento
	t_stack_node	*cheapest_node; //Para armazenar um ponteiro para o nó mais barato até o momento

	if (!stack) //Verifica se a pilha está vazia
		return ;
	cheapest_value = LONG_MAX; //Atribui o maior valor possível de `long` como o valor mais barato até o momento
	while (stack) //Percorre todos os nós até o final da pilha e encontra o nó mais barato
	{
		if (stack->push_cost < cheapest_value) //Verifica se o custo de movimento do nó atual é menor que o valor mais barato até o momento
		{
			cheapest_value = stack->push_cost; //Se sim, atualiza o valor mais barato para o custo de movimento do nó atual
			cheapest_node = stack; //Atribui o nó atual como o nó mais barato até o momento
		}
		stack = stack->next; //Move para o próximo nó para comparação
	}
	cheapest_node->cheapest = TRUE; //Após percorrer a pilha, se não for encontrado um nó mais barato, define o atributo `cheapest` do nó mais barato como `verdadeiro` na estrutura de dados
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) //Define uma função que combina todas as funções necessárias para preparar a pilha `a`, pronta para as operações de movimentação e ordenação. Essas funções definem os dados dentro da estrutura do nó
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
