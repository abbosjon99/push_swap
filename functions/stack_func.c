/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:40:54 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 20:45:06 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Just an atoi for long long int
long long int	ft_atoll(const char *str)
{
	int				ispos;
	long long int	val;

	ispos = 1;
	val = 0;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ispos *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + *str - '0';
		str++;
		if (val == LLONG_MAX / 10 && ispos == -1 && *str == '8')
			return (LLONG_MIN);
	}
	return (val * ispos);
}

t_stack	*ft_findlastnode(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_stacklen(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

bool	ft_isstack_sorted(t_stack *a)
{
	int	tmpvalue;

	tmpvalue = a->value;
	a = a->next;
	while (a)
	{
		if (a->value <= tmpvalue)
			return (0);
		tmpvalue = a->value;
		a = a->next;
	}
	return (1);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
