/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:22:37 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 17:40:08 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if nothing is returns main returns 0;
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argv++;
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		if (!argv)
			return (1);
	}
	ft_make_stack(&a, argv, argc == 2);
	if (!ft_isstack_sorted(a))
	{
		if (ft_stacklen(a) == 2)
			sa_sb(a, 1, 1);
		else if (ft_stacklen(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	ft_free_stack(&a);
}
