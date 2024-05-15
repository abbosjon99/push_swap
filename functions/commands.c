/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:22:37 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 21:40:33 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// I dont think we physically need to change stacks
// let's just change the value:))

void	sa_sb(t_stack *stack, bool printit, bool isit_sa)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	if (printit)
	{
		if (isit_sa)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a, 0, 0);
	sa_sb(b, 0, 0);
	ft_printf("ss\n");
}

void	pa_pb(t_stack **tar, t_stack **dest, bool print_pa)
{
	t_stack	*target;

	if (tar == NULL || dest == NULL)
		return ;
	target = *tar;
	*tar = target->next;
	if (*tar != NULL)
		target->next->prev = NULL;
	target->next = *dest;
	if (*dest != NULL)
		target->next->prev = target;
	*dest = target;
	if (print_pa)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
