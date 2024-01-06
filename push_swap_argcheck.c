/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_argcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welhox <welhox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:55:44 by clundber          #+#    #+#             */
/*   Updated: 2024/01/06 12:37:47 by welhox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_pushatoi(const char *str)

{
	long 	num;
	int			i;
	int			neg;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	neg = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (str[neg] == '-')
		num *= -1;
	return (num);
}

void    ft_error(char **argv, int argc)

{
    if (argc == 2)
        arrayfree(argv);
    ft_putendl_fd("Error", 2);
    exit(0);
}

int numcheck(char *str)
{
    int i;

    i = 0;
    if (!str || !str[0])
        return (0);
    if (str[1] != '\0' && (str[0] == '-' || str[0] == '+'))
        i++;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
            return (0);   
        i++;
    }
    return (1);

}

int    arrayfree(char **array)

{
    int i;

    i = 0;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free (array);
    return(0);
}


int argcheck(int argc, char *argv[])

{
    int i;
    int j;

    i = 1;
    if (argc == 2)
        i = 0;
    while (argv[i])
    {
        if (numcheck(argv[i]) == 0)
            return (0);
        j = 1;
        while (argv[i + j])
        {
            if (ft_strncmp(argv[i], argv[i + j], 12) == 0)
                return (0);
            j++;
        }
        if (ft_pushatoi(argv[i]) > INT_MAX || ft_pushatoi(argv[i]) < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}