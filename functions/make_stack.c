/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:47:21 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/21 10:26:08 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 0 IF INVALID
// "         -15  \t"
static bool	ft_numchecker(char *str)
{
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (false);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

static bool	ft_numfindstack(t_stack *a, int num)
{
	if (a == NULL)
		return (0);
	if (a->value == num)
		return (1);
	return (ft_numfindstack(a->next, num));
}

static int	ft_nodeadd(t_stack **a, int value)
{
	t_stack	*current;
	t_stack	*last;

	if (a == NULL)
		return (1);
	current = malloc(sizeof(t_stack));
	if (!current)
		return (1);
	current->value = value;
	current->next = NULL;
	if (*a == NULL)
	{
		current->prev = NULL;
		*a = current;
	}
	else
	{
		last = ft_findlastnode(*a);
		last->next = current;
		current->prev = last;
	}
	return (0);
}

void	ft_make_stack(t_stack **a, char **argv, bool argvfree)
{
	int				i;
	long long int	value;

	i = 0;
	while (argv[i])
	{
		if (!ft_numchecker(argv[i]))
			error_n_free(a, argv, argvfree);
		value = ft_atoll(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			error_n_free(a, argv, argvfree);
		if (ft_numfindstack(*a, (int)value))
			error_n_free(a, argv, argvfree);
		if (ft_nodeadd(a, (int)value))
			error_n_free(a, argv, argvfree);
		i++;
	}
	if (argvfree)
		free_argv(argv);
}
