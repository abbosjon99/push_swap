/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:24:13 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/12 23:56:50 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Cheapest pushing modes:
// 0. r
// 1. rr
// 2. a - r, b - rr
// 3. a - rr, b - r
// node in b should go top of target a node
// topping the node using only rotate is EQUAL to position LOL
typedef struct s_stack
{
	int				value;
	int				position;
	int				totop_rr;
	int				p_price;
	short int		p_mode;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				ft_make_stack(t_stack **a, char **argv, bool argvfree);
void				ft_free_stack(t_stack **stack);
void				free_argv(char **argv);
void				error_n_free(t_stack **a, char **argv, bool argvfree);
void				final_setittop(t_stack **a, t_stack *max);

void				sa_sb(t_stack *stack, bool printit, bool isit_sa);
void				ss(t_stack *a, t_stack *b);
void				pa_pb(t_stack **tar, t_stack **dest, bool print_pa);
void				ra_rb(t_stack **stack, bool printit, bool isit_ra);
void				rr(t_stack **a, t_stack **b);
void				rra_rrb(t_stack **stack, bool printit, bool isit_rra);
void				rrr(t_stack **a, t_stack **b);

void				tiny_sort(t_stack **a);
void				push_swap(t_stack **a, t_stack **b);

long long int		ft_atoll(const char *str);
int					ft_stacklen(t_stack *a);
int					ft_abc(int a);
int					ft_max(int a, int b);

t_stack				*ft_findlastnode(t_stack *head);
t_stack				*ft_maxstack(t_stack *stack);
void				push_it(t_stack **a, t_stack **b);
bool				ft_isstack_sorted(t_stack *a);

#endif
