/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:18:33 by clundber          #+#    #+#             */
/*   Updated: 2024/01/04 19:46:22 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **a)

{
	if (ps_lstsize(a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			swap_sa(a, 1);
	}	
	else
	{
		if (((*a)->content > (*a)->next->content) && ((*a)->content > (*a)->next->next->content))
			swap_ra(a, 1);
		else if ((*a)->next->content > (*a)->next->next->content)
			swap_rra(a, 1);
		if ((*a)->content > (*a)->next->content)
			swap_sa(a, 1);
	}
}

void	set_info(t_stack **a, t_stack **b)

{
	t_stack *ptr;

	median_check(a);
	median_check(b);
	push_cost(a);
	push_cost(b);
	cheapest(a);
	cheapest(b);
	ptr = *a;
	while (ptr->next)
	{
		b_target(&ptr, b);
		ptr = ptr->next;
	}
	ptr = *b;
	while (ptr->next)
	{
		a_target(&ptr, a);
		ptr = ptr->next;
	}
}

void	move_to_b(t_stack **a, t_stack **b)

{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while(aptr->next && aptr->cheapest == false)
		aptr = aptr->next;
	while(bptr->next && aptr->target != bptr)
		bptr = bptr->next;
	while (aptr->index != 0 && bptr->index != 0)
	{
		if (aptr->above_median == true && bptr->above_median == true)
			swap_rr(a, b);
		else if (aptr->above_median == false && bptr->above_median == false)
			swap_rrr(a, b);
		else
			break;
	}
	
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
	swap_pb(a, b);
}

void	move_to_a(t_stack **a, t_stack **b)

{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while(bptr->next && bptr->cheapest == false)
		bptr = bptr->next;
	while(aptr->next && bptr->target != aptr)
		aptr = aptr->next;
	while (bptr->index != 0 && aptr->index != 0)
	{
		if (bptr->above_median == true && aptr->above_median == true)
			swap_rr(a, b);
		else if (bptr->above_median == false && aptr->above_median == false)
			swap_rrr(a, b);
		else
			break;
	}
	
	while (aptr->index != 0)
	{
		if (bptr->above_median == true)
			swap_ra(a, 1);
		else
			swap_rra(a, 1);
	}
		while (aptr->index != 0)
	{
		if (aptr->above_median == true)
			swap_rb(b, 1);
		else
			swap_rrb(b, 1);
	}
	swap_pa(a, b);
}

void	ft_sorter(t_stack **a, t_stack **b)

{
	swap_pb(a, b);
	if (ps_lstsize(a) > 3)
		swap_pb(a, b);
	//ft_listcheck(a, b);	
	while (ps_lstsize(a) > 3)
	{
		set_info(a, b);
		move_to_b(a, b);
	}
	ft_listcheck(a, b); //DELETE
	tiny_sort(a);
	ft_listcheck(a, b); //DELETE
	while (*b)
	{
		set_info(a, b);
		move_to_a(a, b);
	}
/* 	while (b)
	{
		//move over to a with target
	} */
}

int	algo_control(t_stack **stack_a, t_stack **stack_b)

{
	if (ft_sorted(stack_a, stack_b) == 1)
		return(1);
	if (ps_lstsize(stack_a) <= 3)
	{
		tiny_sort(stack_a);
		return(1);
	}
	else
		ft_sorter(stack_a, stack_b);
	//if (ft_sorted(stack_a, stack_b) == 1)
	return(1);	
	return(0);
}