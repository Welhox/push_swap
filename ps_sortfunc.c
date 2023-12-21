/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:19:19 by clundber          #+#    #+#             */
/*   Updated: 2023/12/21 17:17:06 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_sasb(t_stack *stack_a)

{
	t_stack *ptr;

	ptr = NULL;
	ptr = stack_a->next;
	stack_a->next = ptr->next;
	ptr->next = stack_a;
	return (ptr);
}

/* t_stack	*swap_pa(t_stack **stack_a, t_stack **stack_b)

{


	
} */


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