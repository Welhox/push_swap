/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:28 by clundber          #+#    #+#             */
/*   Updated: 2024/02/07 15:03:38 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_rotate(t_stack *aptr, t_stack *bptr, t_stack **a, t_stack **b)

{
	while (aptr->index != 0)
	{
		if (aptr->above_median == true)
			swap_ra(a, 1);
		else
			swap_rra(a, 1);
	}
	while (bptr->index != 0)
	{
		if (bptr->above_median == true)
			swap_rb(b, 1);
		else
			swap_rrb(b, 1);
	}
}

void	dual_rotate_b(t_stack *aptr, t_stack *bptr, t_stack **a, t_stack **b)

{
	while (aptr->index != 0 && bptr->index != 0)
	{
		if (aptr->above_median == true && bptr->above_median == true)
			swap_rr(a, b);
		else if (aptr->above_median == false && bptr->above_median == false)
			swap_rrr(a, b);
		else if (aptr->above_median == true
			&& (aptr->index >= bptr->index - bptr->med))
			bptr->above_median = true;
		else if (aptr->above_median == false
			&& (aptr->index <= bptr->index - bptr->med))
			bptr->above_median = false;
		else
			break ;
	}
}

void	dual_rotate_a(t_stack *aptr, t_stack *bptr, t_stack **a, t_stack **b)

{
	while (bptr->index != 0 && aptr->index != 0)
	{
		if (bptr->above_median == true && aptr->above_median == true)
			swap_rr(a, b);
		else if (bptr->above_median == false && aptr->above_median == false)
			swap_rrr(a, b);
		else if (bptr->above_median == true
			&& (bptr->index >= aptr->index - aptr->med))
			aptr->above_median = true;
		else if (bptr->above_median == false
			&& (bptr->index <= aptr->index - aptr->med))
			aptr->above_median = false;
		else
			break ;
	}
}

void	move_to_b(t_stack **a, t_stack **b)

{
	t_stack	*aptr;
	t_stack	*bptr;

	aptr = *a;
	bptr = *b;
	while (aptr && aptr->cheapest == false)
		aptr = aptr->next;
	while (bptr && aptr->target != bptr)
		bptr = bptr->next;
	dual_rotate_b(aptr, bptr, a, b);
	median_check(b);
	single_rotate(aptr, bptr, a, b);
	swap_pb(a, b);
}

void	move_to_a(t_stack **a, t_stack **b)

{
	t_stack	*aptr;
	t_stack	*bptr;

	aptr = *a;
	bptr = *b;
	while (bptr && bptr->cheapest == false)
		bptr = bptr->next;
	while (aptr && bptr->target != aptr)
		aptr = aptr->next;
	dual_rotate_a(aptr, bptr, a, b);
	median_check(a);
	single_rotate(aptr, bptr, a, b);
	swap_pa(a, b);
}
