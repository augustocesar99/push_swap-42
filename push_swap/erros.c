# include "../push_swap.h"

int     error_syntax(chat *str_n) // Define uma função para lidar com erros de sintaxe e retorna `1` para `erro` caso alguma das seguintes condições seja atendida
{
	if (!(*str_n == '+' || *str_n == '-' || ft_isdigit(*str_n)))
		return (1);
	if ((*str_n == '+' || *str_n == '-') &&
			!(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	erro_duplicate(t_stack_node *a, int n) // Define uma função que verifica números de entrada duplicados na pilha `a`
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->valeu == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack) // Define uma função para liberar uma pilha em caso de erro
{
	t_stack_node *temp;
	t_stack_node *current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->valeu = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void free_error(t_stack_node **a) // Define uma função que, ao encontrar um erro, libera a pilha e imprime uma mensagem de erro
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}