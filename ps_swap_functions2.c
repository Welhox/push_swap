/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:59:27 by clundber          #+#    #+#             */
/*   Updated: 2024/01/10 17:27:46 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rb(t_stack **stack_b, int i)

{
	t_stack	*b_ptr;

	if (*stack_b)
	{
		b_ptr = NULL;
		b_ptr = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		ps_lstadd_back(stack_b, b_ptr);
		b_ptr->next = NULL;
		if (i == 1)
			ft_printf("rb\n");
		ft_index(stack_b);
	}
}

void	swap_rr(t_stack **stack_a, t_stack **stack_b)

{
	if (*stack_a && *stack_b)
	{
		swap_ra(stack_a, 0);
		swap_rb(stack_b, 0);
		write(1, "rr\n", 3);
	}
}

void	swap_rra(t_stack **stack_a, int i)

{
	t_stack	*a_ptr;
	t_stack	*a2_ptr;

	if (*stack_a)
	{
		a_ptr = NULL;
		a2_ptr = NULL;
		a_ptr = (*stack_a);
		a2_ptr = (*stack_a);
		(*stack_a) = ps_lstlast(*stack_a);
		while (a_ptr->next->next)
			a_ptr = a_ptr->next;
		(*stack_a)->next = a2_ptr;
		a_ptr->next = NULL;
		if (i == 1)
			ft_printf("rra\n");
		ft_index(stack_a);
	}
}

void	swap_rrb(t_stack **stack_b, int i)

{
	t_stack	*b_ptr;
	t_stack	*b2_ptr;

	if (*stack_b)
	{
		b_ptr = NULL;
		b2_ptr = NULL;
		b_ptr = (*stack_b);
		b2_ptr = (*stack_b);
		(*stack_b) = ps_lstlast(*stack_b);
		while (b_ptr->next->next)
			b_ptr = b_ptr->next;
		(*stack_b)->next = b2_ptr;
		b_ptr->next = NULL;
		if (i == 1)
			ft_printf("rrb\n");
		ft_index(stack_b);
	}
}

void	swap_rrr(t_stack **stack_a, t_stack **stack_b)

{
	if (*stack_a && *stack_b)
	{
		swap_rra(stack_a, 0);
		swap_rrb(stack_b, 0);
		write(1, "rrr\n", 4);
	}
}
