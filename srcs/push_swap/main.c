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

static char	*ft_strjoin_multiple(int count, char **argv, const char *delimiter)
{
	int		i;
	int		total_length;
	char	*result;
	char	*ptr;

	total_length = 0;
	i = 0;
	while (i < count)
		total_length += ft_strlen(argv[i++]) + ft_strlen(delimiter);
	result = malloc(total_length + 1);
	if (!result)
		return (NULL);
	ptr = result;
	i = 0;
	while (i < count)
	{
		ptr += ft_strlcpy(ptr, argv[i], total_length - (ptr - result) + 1);
		if (i < count - 1)
			ptr += ft_strlcpy(ptr, delimiter, total_length - (ptr - result) + 1);
		i++;
	}
	*ptr = '\0';
	return (result);
}

static int	is_repeated(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[j] != NULL)
		{
			if (argv[i] == argv[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_number_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

static int	process_arguments(int argc, char **argv,
	t_stack_node **a, char ***split_argv)
{
	char	*joined;
	int		wc;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	joined = ft_strjoin_multiple(argc - 1, &argv[1], " ");
	if (!joined || !is_valid_number_string(joined))
	{
		if (joined)
			free(joined);
		ft_printf("Error\n");
		return (1);
	}
	wc = count_wd(joined, ' ');
	*split_argv = ft_split(joined, ' ');
	free(joined);
	if (!*split_argv || is_repeated(*split_argv))
	{
		if (*split_argv)
			free_split(*split_argv, wc);
		ft_printf("Error\n");
		return (!*split_argv);
	}
	init_stack_a(a, *split_argv);
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

