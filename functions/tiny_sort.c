/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:46:47 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 12:56:23 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*findmaxstack(t_stack *a)
{
	t_stack	*max;

	max = a;
	a = a->next;
	while (a)
	{
		if (max->value < a->value)
			max = a;
		a = a->next;
	}
	return (max);
}

// sorts stacks max length of 2
// maximum allowed turns is 3;
// 1. Find the Max value and put it on the bottom
// 2. Check the remaining two
void	tiny_sort(t_stack **a)
{
	t_stack	*max;

	max = findmaxstack(*a);
	if (max->prev == NULL)
		ra_rb(a, 1, 1);
	else if (max->next != NULL)
		rra_rrb(a, 1, 1);
	if (!ft_isstack_sorted(*a))
		sa_sb(*a, 1, 1);
}
