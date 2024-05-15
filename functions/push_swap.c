/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:37:03 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/13 01:23:56 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// We should start indexing from 0 to make is easy to compute
static int	ft_stackposition(t_stack *a)
{
	int	i;

	i = -1;
	while (a)
	{
		a = a->prev;
		i++;
	}
	return (i);
}

// We'll set price for topping it to each a element
// I'm too lazy that's why I wrote it so it will set values to b too.
static void	set_top_it_price(t_stack *a, t_stack *b, bool set_btoo)
{
	int	len;

	len = ft_stacklen(a);
	while (a)
	{
		a->position = ft_stackposition(a);
		a->totop_rr = len - a->position;
		if (a->prev == NULL)
			a->totop_rr = 0;
		a = a->next;
	}
	if (set_btoo)
		set_top_it_price(b, NULL, 0);
}

// we have max value in stack a so we don't need to check if the node is more
static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*max;

	if (!a || !b)
		return ;
	max = ft_maxstack(a);
	while (b)
	{
		b->target = max;
		temp = a;
		while (temp)
		{
			if (b->value < temp->value && temp->value < b->target->value)
				b->target = temp;
			temp = temp->next;
		}
		b = b->next;
	}
}

// 1. push everything except the max to stack b
// leave 3 elements on stack a and do tiny sort
void	push_swap(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*max;

	len = ft_stacklen(*a);
	max = ft_maxstack(*a);
	while (len > 3)
	{
		if (*a == max)
		{
			ra_rb(a, 1, 1);
			continue ;
		}
		pa_pb(a, b, 0);
		len--;
	}
	tiny_sort(a);
	while (*b != NULL)
	{
		set_top_it_price(*a, *b, 1);
		set_target(*a, *b);
		push_it(a, b);
	}
	set_top_it_price(*a, NULL, 0);
	if (!ft_isstack_sorted(*a))
		final_setittop(a, max);
}

t_stack	*ft_maxstack(t_stack *stack)
{
	t_stack	*max;

	if (stack == NULL)
		return (stack);
	max = stack;
	stack = stack->next;
	while (stack)
	{
		if (max->value < stack->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
