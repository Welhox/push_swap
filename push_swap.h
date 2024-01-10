/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:58:07 by clundber          #+#    #+#             */
/*   Updated: 2024/01/10 18:40:21 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_stack
{
	int				content;
	int				index;
	int				push_cost;
	t_bool			cheapest;
	t_bool			above_median;
	int				med;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

//		argument check & list prepping

long	ft_atol(const char *str);
int		argcheck(int argc, char *argv[]);
int		numcheck(char *str);
int		arrayfree(char **array);
void	ft_index(t_stack **stack);
int		ft_sorted(t_stack **stack_a, t_stack **stack_b);
void	ft_error(char **argv, int argc);

//		sorting algorithm

int		algo_control(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack_a);
void	ft_sorter(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	push_cost(t_stack **stack, int i);
void	cheapest(t_stack **stack);
void	move_to_b(t_stack **a, t_stack **b);
void	move_to_a(t_stack **a, t_stack **b);
t_stack	*find_max(t_stack **stack);
t_stack	*find_min(t_stack **stack);
void	b_target(t_stack **node, t_stack **b_stack);
void	a_target(t_stack **node, t_stack **a_stack);
void	median_check(t_stack **stack);
void	set_info(t_stack **a, t_stack **b);
void	dual_rotate_a(t_stack *aptr, t_stack *bptr, t_stack **a, t_stack **b);
void	dual_rotate_b(t_stack *aptr, t_stack *bptr, t_stack **a, t_stack **b);
void	single_rotate(t_stack *aptr, t_stack *bptr, t_stack **a, t_stack **b);

//		lst manipulation functions

void	ps_lstadd_front(t_stack **lst, t_stack *new);
int		ps_lstadd_back(t_stack **lst, t_stack *new);
int		ps_lstsize(t_stack **lst);
t_stack	*ps_lstlast(t_stack *lst);
t_stack	*ps_lstnew(int content);
void	lst_clear(t_stack **stack);

//		swapping functions

void	swap_sa(t_stack **stack_a, int i);
void	swap_sb(t_stack **stack_b, int i);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	swap_pb(t_stack **stack_a, t_stack **stack_b);
void	swap_pa(t_stack **stack_a, t_stack **stack_b);
void	swap_ra(t_stack **stack_a, int i);
void	swap_rb(t_stack **stack_b, int i);
void	swap_rr(t_stack **stack_a, t_stack **stack_b);
void	swap_rra(t_stack **stack_a, int i);
void	swap_rrb(t_stack **stack_b, int i);
void	swap_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
