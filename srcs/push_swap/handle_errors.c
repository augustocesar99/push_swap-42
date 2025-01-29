/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:11:23 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 14:11:28 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_syntax(char *str_n) //Define uma função para tratar erros de sintaxe e retorna `1` em caso de erro, caso qualquer uma das condições a seguir seja atendida
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Verifica se o primeiro caractere da string de entrada não contém um sinal ou um dígito
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Verifica se o primeiro caractere da string de entrada contém um sinal, mas o segundo caractere não contém um dígito
		return (1);
	while (*++str_n) //Se as condições de erro acima não forem atendidas, pré-incrementa para apontar para o próximo caractere da string e faz um loop até o final da string
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Verifica se o próximo caractere na string não é um dígito
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n) //Define uma função que verifica números duplicados na pilha `a`
{
	if (!a) //Verifica se a pilha está vazia
		return (0);
	while (a) //Faz um loop até o final da pilha `a` ser alcançado
	{
		if (a->nbr == n) //Verifica se o valor do nó atual é igual a `n`. Consulte `init_stack_a()`
			return (1);
		a = a->next; //Move para o próximo nó para verificar duplicatas
	}
	return (0);
}

void	free_stack(t_stack_node **stack) //Define uma função para liberar a pilha caso ocorram erros
{
	t_stack_node	*tmp; //Para armazenar o próximo nó na pilha antes que o nó atual seja liberado, porque uma vez que um nó é liberado, não é possível acessar seu ponteiro `next`
	t_stack_node	*current;

	if (!stack) //Verifica se a pilha está vazia
		return ;
	current = *stack;
	while (current) //Enquanto houver um nó na pilha
	{
		tmp = current->next; //Atribui a `tmp` o ponteiro para o próximo nó
		current->nbr = 0; //Atribuir `0` ao nó antes de liberá-lo não é estritamente necessário, mas pode ajudar a capturar possíveis bugs, como vazamentos de memória, e melhorar a depuração
		free(current); //Libera o nó atual, desalocando a memória ocupada por esse nó
		current = tmp; //Atribui `tmp` como o próximo nó da pilha
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a) //Define uma função que, ao encontrar um erro único, libera a pilha e imprime uma mensagem de erro
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
