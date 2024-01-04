/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:45:23 by clundber          #+#    #+#             */
/*   Updated: 2024/01/04 19:51:40 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack **stack)

{
	int	max;
	t_stack *ptr;

	ptr = *stack;
	max = INT_MIN;
	while (ptr->next)
	{
		if (ptr->content > max)
			max = ptr->content;
		ptr = ptr->next;
	}
	return (max);
}

int find_min(t_stack **stack)

{
	int	min;
	t_stack *ptr;

	ptr = *stack;
	min = INT_MAX;
	while (ptr->next)
	{
		if (ptr->content < min)
			min = ptr->content;
		ptr = ptr->next;
	}
	return (min);
}

void	b_target(t_stack **node, t_stack **b_stack)

{
	int	target_size;
	t_stack *ptr;
	t_stack *target_node;

	ptr = *b_stack;
	target_size = find_max(b_stack); 
	while (ptr->next)
	{
		if (ptr->content < (*node)->content && (ptr->content > target_size || target_size == find_max(b_stack)))
		{	
			target_size = ptr->content;
			target_node = ptr;
		}
		else if(ptr->content == target_size)
			target_node = ptr;
		ptr = ptr->next;
	}
	(*node)->target = target_node;
}

void	a_target(t_stack **node, t_stack **a_stack)

{
	int	target_size;
	t_stack *ptr;
	t_stack *target_node;

	ptr = *a_stack;
	target_size = find_min(a_stack);
	while (ptr->next)
	{
		if (ptr->content > (*node)->content && (ptr->content < target_size || target_size == find_min(a_stack)))
		{	
			target_size = ptr->content;
			target_node = ptr;
		}
		else if(ptr->content == target_size)
			target_node = ptr;
		ptr = ptr->next;
	}
	(*node)->target = target_node;
}

void	median_check(t_stack **stack)

{
	int	median;
	t_stack *ptr;

	ptr = *stack;
	median = 0;
	median = ps_lstsize(stack) / 2;
	while (ptr->next)
	{
		if (ptr->index > median)
			ptr ->above_median = true;
		else
			ptr->above_median = false;
		ptr = ptr->next;
	}
}

void	push_cost(t_stack **stack)

{
	t_stack *ptr;

	ptr = *stack;
	while (ptr->next)
	{
		if (ptr->above_median == true)
			ptr->push_cost = ptr->index;
		else
			ptr->push_cost = ps_lstsize(stack) - ptr->index; 
		ptr = ptr->next;
	}
}

void	cheapest(t_stack **stack)

{
	t_stack *ptr;
	int		spot;
	int		cost;

	cost = INT_MAX;
	spot = 0;
	ptr = *stack;
	while (ptr->next)
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
	while (ptr->next)
	{
		if (ptr->index == spot)
			ptr->cheapest = true;
		ptr = ptr->next;
	}
}