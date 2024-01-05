/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:29 by welhox            #+#    #+#             */
/*   Updated: 2024/01/05 16:38:49 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_index(t_stack **stack)

{
    if (*stack)
    {
        t_stack *ptr;
        int i;

        ptr = NULL;
        i = 1;
        ptr = (*stack);
        ptr->index = 0;

        while(ptr->next)
        {
            ptr = ptr->next;
            ptr->index = i;
            i++;
        }
    }

}

int ft_makelist(char *argv[], t_stack **stack_a, int argc)

{
    int i;
    int number;

    number = 0;
    i = 1;
    if (argc == 2)
        i = 0;
      while (argv[i])
    {
        number = ft_atoi(argv[i]);
        ps_lstadd_back(stack_a, ps_lstnew(number));
        // malloc check / freeing function
        i++;
    }
    ft_index(stack_a);

    return (1);
}

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

int ft_sorted(t_stack **stack_a, t_stack **stack_b)

{
    t_stack *ptr = NULL;

    ptr = (*stack_a);

    if (*stack_a && !*stack_b)
    {
        while (ptr->next)
        {
            if (ptr->content > ptr->next->content)
                return (0);
            ptr = ptr->next;
        }
        return(1);
    }
    return(0);

}

void    lst_clear(t_stack **stack)

{
    t_stack *ptr;
    t_stack *ptr2;

    if (*stack)
    {
        ptr = *stack;
        while (ptr->next)
        {
        ptr2 = ptr->next;
        free(ptr);
        ptr = ptr2;
        }
        free (ptr);
    }

}
int main(int argc, char *argv[])

{
   // int argc = 2;
    //char *argv[50] = {"a.out", "1 2 3 3"};
    t_stack  *stack_a = NULL;
    t_stack  *stack_b = NULL;
    char    **array;

    if (argc == 2)
    {
        array = ft_split(argv[1], ' ');
        if (array[1] == NULL)
            return(arrayfree(array));
        if (oneargcheck(array) == 0)
        {
            ft_putendl_fd("Error", 2);
            exit (0);
            //return (0);
        }
        if (ft_makelist(array, &stack_a, argc) == 0)
            return (0);
        arrayfree(array);  
    }
    else
    {
        if (argcheck(argc, argv) == 0)
        {    
            ft_putendl_fd("Error", 2);
            exit (0);
            //return (0);
        }
        if (ft_makelist(argv, &stack_a, argc) == 0)
            return (0);     
    }
    algo_control(&stack_a, &stack_b);
    lst_clear(&stack_a);
    lst_clear(&stack_b);
    //ft_listcheck(&stack_a, &stack_b);
    //freeing func
    //if (ft_sorted(&stack_a, &stack_b) == 1)
    //    ft_printf("sorting completed\n");
   

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