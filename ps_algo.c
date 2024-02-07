/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:18:33 by clundber          #+#    #+#             */
/*   Updated: 2024/02/07 15:03:36 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **a)

{
	if (ps_lstsize(a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			swap_sa(a, 1);
	}
	else
	{
		if (((*a)->content > (*a)->next->content)
			&& ((*a)->content > (*a)->next->next->content))
			swap_ra(a, 1);
		else if ((*a)->next->content > (*a)->next->next->content)
			swap_rra(a, 1);
		if ((*a)->content > (*a)->next->content)
			swap_sa(a, 1);
	}
}

void	set_info(t_stack **a, t_stack **b)

{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		b_target(&ptr, b);
		ptr = ptr->next;
	}
	ptr = *b;
	while (ptr)
	{
		a_target(&ptr, a);
		ptr = ptr->next;
	}
	median_check(a);
	median_check(b);
	push_cost(a, 0);
	push_cost(b, 0);
}

void	rotate(t_stack **a)

{
	t_stack	*smallest;
	t_stack	*ptr;

	smallest = find_min(a);
	ptr = *a;
	while (ptr)
	{
		if (ptr == smallest)
		{
			if (ptr->above_median == true)
			{
				while (ptr->index != 0)
					swap_ra(a, 1);
				break ;
			}
			else
			{
				while (ptr->index != 0)
					swap_rra(a, 1);
				break ;
			}
		}
		ptr = ptr->next;
	}
}

void	ft_sorter(t_stack **a, t_stack **b)

{
	swap_pb(a, b);
	if (ps_lstsize(a) > 3)
		swap_pb(a, b);
	while (ps_lstsize(a) > 3)
	{
		set_info(a, b);
		push_cost(a, 1);
		cheapest(a);
		move_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		set_info(a, b);
		push_cost(b, 1);
		cheapest(b);
		move_to_a(a, b);
	}
	median_check(a);
	rotate(a);
}

int	algo_control(t_stack **stack_a, t_stack **stack_b)

{
	if (ft_sorted(stack_a, stack_b) == 1)
		return (1);
	if (ps_lstsize(stack_a) <= 3)
	{
		tiny_sort(stack_a);
		return (1);
	}
	else
		ft_sorter(stack_a, stack_b);
	return (1);
}
