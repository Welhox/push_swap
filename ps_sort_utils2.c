/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:52:46 by clundber          #+#    #+#             */
/*   Updated: 2024/02/07 15:03:40 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ra(t_stack **stack_a, int i)

{
	t_stack	*a_ptr;

	if (*stack_a)
	{
		a_ptr = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		ps_lstadd_back(stack_a, a_ptr);
		a_ptr->next = NULL;
		if (i == 1)
			ft_printf("ra\n");
		ft_index(stack_a);
	}
}

void	push_cost(t_stack **stack, int i)

{
	t_stack	*ptr;

	ptr = *stack;
	if (i == 0)
	{
		while (ptr)
		{
			if (ptr->above_median == true)
				ptr->push_cost = ptr->index;
			else
				ptr->push_cost = ps_lstsize(stack) - ptr->index;
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			ptr->push_cost += ptr->target->push_cost;
			ptr = ptr->next;
		}
	}
}

void	cheapest(t_stack **stack)

{
	t_stack	*ptr;
	int		spot;
	int		cost;

	cost = INT_MAX;
	spot = 0;
	ptr = *stack;
	while (ptr)
	{
		ptr->cheapest = false;
		if (ptr->push_cost < cost)
		{
			cost = ptr->push_cost;
			spot = ptr->index;
		}
		ptr = ptr->next;
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->index == spot)
			ptr->cheapest = true;
		ptr = ptr->next;
	}
}
