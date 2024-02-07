/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:19:19 by clundber          #+#    #+#             */
/*   Updated: 2024/02/07 15:03:41 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack **stack_a, int i)

{
	t_stack	*ptr;
	t_stack	*ptr2;

	if (*stack_a)
	{
		ptr2 = NULL;
		ptr = NULL;
		ptr = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		ptr2 = (*stack_a)->next;
		(*stack_a)->next = ptr;
		ptr->next = ptr2;
		if (i == 1)
			write(1, "sa\n", 3);
		(*stack_a)->index = 0;
		(*stack_a)->next->index = 1;
	}
}

void	swap_sb(t_stack **stack_b, int i)

{
	t_stack	*ptr;
	t_stack	*ptr2;

	if (*stack_b)
	{
		ptr2 = NULL;
		ptr = NULL;
		ptr = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		ptr2 = (*stack_b)->next;
		(*stack_b)->next = ptr;
		ptr->next = ptr2;
		if (i == 1)
			write(1, "sb\n", 3);
		(*stack_b)->index = 0;
		(*stack_b)->next->index = 1;
	}
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)

{
	if (*stack_a && *stack_b)
	{
		swap_sa(stack_a, 0);
		swap_sb(stack_b, 0);
		write(1, "ss\n", 3);
	}
}

void	swap_pb(t_stack **stack_a, t_stack **stack_b)

{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	if (*stack_a)
	{
		a_ptr = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		if (*stack_b == NULL)
		{
			(*stack_b) = a_ptr;
			(*stack_b)->next = NULL;
		}
		else
		{
			b_ptr = (*stack_b);
			(*stack_b) = a_ptr;
			(*stack_b)->next = b_ptr;
		}
		write(1, "pb\n", 3);
		ft_index(stack_a);
		ft_index(stack_b);
	}
}

void	swap_pa(t_stack **stack_a, t_stack **stack_b)

{
	t_stack	*b_ptr;
	t_stack	*a_ptr;

	if (*stack_b)
	{
		a_ptr = NULL;
		b_ptr = NULL;
		a_ptr = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		if (*stack_a == NULL)
		{
			(*stack_a) = a_ptr;
			(*stack_a)->next = NULL;
		}
		else
		{
			b_ptr = (*stack_a);
			(*stack_a) = a_ptr;
			(*stack_a)->next = b_ptr;
		}
		write(1, "pa\n", 3);
		ft_index(stack_a);
		ft_index(stack_b);
	}
}
