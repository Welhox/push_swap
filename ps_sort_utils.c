/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:45:23 by clundber          #+#    #+#             */
/*   Updated: 2024/01/10 18:22:26 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack **stack)

{
	int		max;
	t_stack	*ptr;

	ptr = *stack;
	max = INT_MIN;
	while (ptr)
	{
		if (ptr->content > max)
			max = ptr->content;
		ptr = ptr->next;
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->content == max)
			break ;
		ptr = ptr->next;
	}
	return (ptr);
}

t_stack	*find_min(t_stack **stack)

{
	int		min;
	t_stack	*ptr;

	ptr = *stack;
	min = INT_MAX;
	while (ptr)
	{
		if (ptr->content < min)
			min = ptr->content;
		ptr = ptr->next;
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->content == min)
			break ;
		ptr = ptr->next;
	}
	return (ptr);
}

void	b_target(t_stack **node, t_stack **b_stack)

{
	int		target_size;
	t_stack	*ptr;
	t_stack	*target_node;

	ptr = *b_stack;
	target_size = INT_MIN;
	target_node = find_max(b_stack);
	while (ptr)
	{
		if (ptr->content < (*node)->content && ptr->content >= target_size)
		{
			target_size = ptr->content;
			target_node = ptr;
		}
		ptr = ptr->next;
	}
	(*node)->target = target_node;
}

void	a_target(t_stack **node, t_stack **a_stack)

{
	int		target_size;
	t_stack	*ptr;
	t_stack	*target_node;

	ptr = *a_stack;
	target_size = INT_MAX;
	target_node = find_min(a_stack);
	while (ptr)
	{
		if (ptr->content > (*node)->content && ptr->content <= target_size)
		{
			target_size = ptr->content;
			target_node = ptr;
		}
		ptr = ptr->next;
	}
	(*node)->target = target_node;
}

void	median_check(t_stack **stack)

{
	int		median;
	t_stack	*ptr;

	ptr = *stack;
	median = 0;
	median = ps_lstsize(stack) / 2;
	while (ptr)
	{
		if (ptr->index <= median)
			ptr->above_median = true;
		else
			ptr->above_median = false;
		ptr->med = median;
		ptr = ptr->next;
	}
}
