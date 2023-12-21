/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:29 by welhox            #+#    #+#             */
/*   Updated: 2023/12/21 16:49:18 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_makelist(char *argv[], t_stack *stack_a)

{
    int i;
    int number;

    number = 0;
    i = 2;
    stack_a->content = ft_atoi(argv[1]);
    stack_a->next = NULL;
      while (argv[i])
    {
        number = ft_atoi(argv[i]);
        ps_lstadd_back(&stack_a, ps_lstnew(number)); 
        i++;
    }

    return (1);
}

void   ft_listcheck(t_stack *stack_a, t_stack *stack_b) //DELETE

{
    t_stack *aptr;
    t_stack *bptr;

    aptr = NULL;
    bptr = NULL;

    aptr = stack_a;
    bptr = stack_b;
    ft_printf("A = %d\n", (aptr->content));
    while (aptr->next)
    {
        aptr = aptr->next;
        ft_printf("A = %d\n", (aptr->content));
    }
    ft_printf("B = %d\n", (bptr->content));
    while (bptr->next)
    {
        bptr = bptr->next;
        ft_printf("B = %d\n", (bptr->content));
    }

}

int main(int argc, char *argv[])

{
    t_stack  *stack_a = NULL;
    stack_a = malloc(sizeof(t_stack));
    t_stack  *stack_b = NULL;
    stack_b = malloc(sizeof(t_stack));
  /*   if (!stack_a)
        return (0); */
   // stack_a = NULL;
    //stack_b = NULL;
    stack_b->next = NULL;

    if (argcheck(argc, argv) == 0)
    {
        ft_putendl_fd("ERROR", 1);
        return (0);  
    }
    if (ft_makelist(argv, stack_a) == 0)
        return (0);
    stack_a = swap_sasb(stack_a);
    ft_listcheck(stack_a, stack_b);
    ft_printf("Great success\n");
    return(0);
}





/* V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

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