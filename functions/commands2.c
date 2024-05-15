/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:22:37 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 12:58:43 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rotate and reverse rotate together
void	ra_rb(t_stack **stack, bool printit, bool isit_ra)
{
	t_stack	*last;
	t_stack	*first;

	if (stack == NULL || *stack == NULL)
		return ;
	last = ft_findlastnode(*stack);
	first = *stack;
	first->next->prev = NULL;
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (printit)
	{
		if (isit_ra)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra_rb(a, 0, 0);
	ra_rb(b, 0, 0);
	ft_printf("rr\n");
}

void	rra_rrb(t_stack **stack, bool printit, bool isit_rra)
{
	t_stack	*last;
	t_stack	*first;

	if (stack == NULL || *stack == NULL)
		return ;
	last = ft_findlastnode(*stack);
	first = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	if (printit)
	{
		if (isit_rra)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a, 0, 0);
	rra_rrb(b, 0, 0);
	ft_printf("rrr\n");
}
