/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:29 by welhox            #+#    #+#             */
/*   Updated: 2023/12/20 15:34:20 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_makelist(char *argv[], t_list *stack_a)

{
    int i;
    int *ptr;

    ptr = NULL;
    //ptr = stack_a;
    i = 1;
    while (argv[i])
    {
        int content;
    
        content = 0;
        ptr = &content;
        //ft_printf("loop %d\n", i);
        //ft_printf("atoi = %d\n", ft_atoi(argv[i]));
        content = ft_atoi(argv[i]);
        //ptr = &content;
        //ft_printf("int =  %d\n", content);
        ft_lstadd_back(&stack_a, ft_lstnew(ptr));
        i++;
        //ft_printf("loop %d\n", i);
    }
    //ptr = stack_a->content;
    //ft_printf("content = %d\n", (ptr->content));
    return (1);


}

void   ft_listcheck(t_list *stack_a) //DELETE

{
    int i = 0;


    t_list *ptr;

    ptr = NULL;
    ptr = stack_a;
    while (i < 5)
    {
        ft_printf("preprint ok");
        ft_printf("A %d\n", (ptr->content));
        ptr = ptr->next;
        i++;
    }


}

int main(int argc, char *argv[])

{
    t_list  *stack_a;  //= malloc(sizeof (t_list));
    t_list  *stack_b;  //= malloc(sizeof (t_list));



    stack_a = NULL;
    stack_b = NULL;

    if (argcheck(argc, argv) == 0)
    {
        ft_putendl_fd("ERROR", 1);
        return (0);  
    }
    if (ft_makelist(argv, &stack_a) == 0)
        return (0);
    ft_printf("ok before print\n");
    ft_listcheck(&stack_a);
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