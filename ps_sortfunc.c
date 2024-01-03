/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:19:19 by clundber          #+#    #+#             */
/*   Updated: 2024/01/03 12:43:26 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack **stack_a, int i)

{
	t_stack *ptr;
	t_stack *ptr2;

	ptr2 = NULL;
	ptr = NULL;
	ptr = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	ptr2 = (*stack_a)->next;
	(*stack_a)->next = ptr;
	ptr->next = ptr2;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	swap_sb(t_stack **stack_b, int i)

{
	t_stack *ptr;
	t_stack *ptr2;

	ptr2 = NULL;
	ptr = NULL;
	ptr = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	ptr2 = (*stack_b)->next;
	(*stack_b)->next = ptr;
	ptr->next = ptr2;
	if (i == 1)
		write(1, "sb\n", 3);
}

 void	swap_ss(t_stack **stack_a, t_stack **stack_b)

{
	swap_sa(stack_a, 0);
	swap_sb(stack_b, 0);
	write(1, "ss\n", 3);
} 

void	swap_pb(t_stack **stack_a, t_stack **stack_b)

{
	t_stack *a_ptr = NULL;
	//t_stack *b_ptr = NULL;

	a_ptr = (*stack_a);
	(*stack_a) = (*stack_a)->next;

	if(*stack_b == NULL)
	{
		(*stack_b) = a_ptr;
		(*stack_b)->next = NULL;
	}
	else
	ps_lstadd_front(stack_a, a_ptr);
/* 	b_ptr = (*stack_b)->next;
	(*stack_b) = a_ptr;
	(*stack_b)->next = b_ptr; */
	write(1, "pb\n", 3);
/* 	*stack_a = a_ptr;
	b_ptr->next = *stack_b;
	*stack_b = b_ptr; */
}  


/* V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

XX sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

XX sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

XX ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time. */

/* • read, write, malloc, free,
exit
• ft_printf and any equivalent
YOU coded */