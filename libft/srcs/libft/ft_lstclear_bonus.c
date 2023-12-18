/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:46:32 by clundber          #+#    #+#             */
/*   Updated: 2023/11/08 11:58:23 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))

{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *lst;
	ptr2 = *lst;
	while (ptr2)
	{
		ptr2 = ptr2->next;
		del(ptr->content);
		free (ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}
