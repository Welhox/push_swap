/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortfunc3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:52:46 by clundber          #+#    #+#             */
/*   Updated: 2024/01/09 14:19:26 by clundber         ###   ########.fr       */
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
