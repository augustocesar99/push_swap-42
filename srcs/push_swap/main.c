/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:17:10 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/19 11:58:31 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int process_arguments(int argc, char **argv, t_stack_node **a, char ***split_argv)
{
	int i;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ' && argv[1][i] != '-')
				return (1);
			i++;
		}
		*split_argv = ft_split(argv[1], ' ');
		if (!*split_argv)
			return (1);
		argv = *split_argv;
	}
	init_stack_a(a, argv + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;

	a = NULL;
	b = NULL;
	split_argv = NULL;
	if (process_arguments(argc, argv, &a, &split_argv))
		return (1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (split_argv)
		free_split(split_argv, count_wd(argv[1], ' '));
	free_stack(&a);
	return (0);
}
