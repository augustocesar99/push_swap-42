/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:17:10 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/29 15:29:28 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int argc, char **argv) //Define um programa que recebe uma entrada de números aleatórios e os ordena em ordem crescente
{
	t_stack_node	*a; //Para armazenar um ponteiro para a pilha `a`
	t_stack_node	*b; //Para armazenar um ponteiro para a pilha `b`

	a = NULL; //Define ambos os ponteiros como NULL para evitar comportamentos indefinidos
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Verifica se há uma quantidade incorreta de argumentos ou se o segundo argumento é `0`
		return (1);
	else if (argc == 2) //Verifica se a quantidade de argumentos é 2 e o segundo não está vazio, isso implica uma string
		argv = split(argv[1], ' '); //Chama `split()` para extrair cada substring
	init_stack_a(&a, argv + 1); //Inicializa a pilha `a`, o que também trata os erros
	if (!stack_sorted(a)) //Verifica se a pilha não está ordenada
	{
		if (stack_len(a) == 2) //Se não estiver, e houver dois números, troca os dois primeiros nós
			sa(&a, FALSE);
		else if (stack_len(a) == 3) //Se não estiver, e houver três números, chama o algoritmo `sort_three`
			sort_three(&a);
		else
			sort_stacks(&a, &b); //Se não estiver, e houver mais de três números, chama o algoritmo `sort_stacks`
	}
	free_stack(&a); //Libera a memória da pilha
	return (0);
}
