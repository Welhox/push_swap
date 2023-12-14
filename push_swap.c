/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welhox <welhox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:29 by welhox            #+#    #+#             */
/*   Updated: 2023/12/14 21:22:20 by welhox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int numcheck(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
            return (0);   
        i++;
    }
    return (1);

}


int argcheck(int argc, char *argv[])

{
    int i;
    int j;

    i = 1;
    if (argc < 3)
        return (0);
    //check for only ints
    while (argv[i]) //&& i < argc)
    {
        if (numcheck(argv[i]) == 0)
            return (0);
        i++;
    }
    i = 1;
    //check for dupes
    while (argv[i])
    {
        j = 1;
        while (argv[i + j])
        {
            if (ft_strncmp(argv[i], argv[i + j], ft_strlen(argv[i])) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int main(int argc, char *argv[])

{
    if (argcheck(argc, argv) == 0)
    {
        ft_putendl_fd("ERROR", 1);
        return (0);
    
    }
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