/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_n_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:45:15 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 10:32:50 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

// We get the entire stack using an array of it(which only has one ptr to stk)
void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	error_n_free(t_stack **a, char **argv, bool argvfree)
{
	ft_free_stack(a);
	if (argvfree)
		free_argv(argv);
	ft_printf("Error\n");
	exit (1);
}
