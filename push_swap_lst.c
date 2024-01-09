/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:12:31 by clundber          #+#    #+#             */
/*   Updated: 2024/01/09 12:01:14 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *lst)

{
	t_stack	*ptr;

	ptr = NULL;
	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_stack	*ps_lstnew(int content)

{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ps_lstadd_back(t_stack **lst, t_stack *new)

{
	if (!new)
		return (0);
	if (*lst)
		ps_lstlast(*lst)->next = new;
	else
		*lst = new;
	return (1);
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)

{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ps_lstsize(t_stack **lst)

{
	int		counter;
	t_stack	*ptr;

	ptr = NULL;
	counter = 0;
	if (!lst)
		return (0);
	ptr = (*lst);
	while (ptr)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}
