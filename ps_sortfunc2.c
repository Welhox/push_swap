/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortfunc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:59:27 by clundber          #+#    #+#             */
/*   Updated: 2024/01/04 19:15:20 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void	swap_rb(t_stack **stack_b, int i)

{
	if (*stack_b)
	{
		t_stack *b_ptr = NULL;

		b_ptr = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		ps_lstadd_back(stack_b, b_ptr);
		b_ptr->next = NULL;
		if (i == 1)
			ft_printf("rb\n");
		ft_index(stack_b);
	}
	else
		ft_printf("rb tried unsuccessfully\n");

} 

void	swap_rr(t_stack **stack_a, t_stack **stack_b)

{
	if (*stack_a && *stack_b)
	{
		swap_ra(stack_a, 0);
		swap_rb(stack_b, 0);
		write(1, "rr\n", 3);
	}
	else
		ft_printf("rr tried unsuccessfully\n");
} 

void	swap_rra(t_stack **stack_a, int i)

{
	if (*stack_a)
	{
		t_stack *a_ptr = NULL;
		t_stack *a2_ptr = NULL;

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
	else
		ft_printf("rra tried unsuccessfully\n");

} 

void	swap_rrb(t_stack **stack_b, int i)

{
	if (*stack_b)
	{
		t_stack *b_ptr = NULL;
		t_stack *b2_ptr = NULL;

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
	else
		ft_printf("rrb tried unsuccessfully\n");

} 

void	swap_rrr(t_stack **stack_a, t_stack **stack_b)

{
	if (*stack_a && *stack_b) 
	{
		swap_rra(stack_a, 0);
		swap_rrb(stack_b, 0);
		write(1, "rrr\n", 4);
	}
	else
		ft_printf("rrr tried unsuccessfully\n");
} 