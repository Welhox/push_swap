/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_graphic_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:06:03 by welhox            #+#    #+#             */
/*   Updated: 2024/01/08 14:18:36 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void   ft_listcheck(t_stack **stack_a, t_stack **stack_b) //DELETE

{
    t_stack *aptr;
    t_stack *bptr;

    aptr = NULL;
    bptr = NULL;

    aptr = (*stack_a);
    bptr = (*stack_b);
    ft_printf("Stack A      Stack B\n");
    ft_printf("--------------------\n");
    if (aptr)
        ft_printf("  %d %d    |    ", (aptr->content), (aptr->index));
    else
        ft_printf("          |    ");
    if (bptr)
        ft_printf("%d %d\n", (bptr->content), (bptr->index));
    else
        ft_printf("  \n");
    while ((aptr && aptr->next) || (bptr && bptr->next))
    {    
        if(aptr && aptr->next)
        {
            aptr = aptr->next;
            ft_printf("  %d %d    |    ", (aptr->content), (aptr->index));
        }
        else
            ft_printf("          |    ");    
        if(bptr && bptr->next)
        {
            bptr = bptr->next;
            ft_printf("%d %d\n", (bptr->content), (bptr->index));
        }
        else
            ft_printf("  \n"); 
    }
    ft_printf("--------------------\n");   
} 