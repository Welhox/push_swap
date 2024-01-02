/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_argcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welhox <welhox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:55:44 by clundber          #+#    #+#             */
/*   Updated: 2024/01/02 12:58:17 by welhox           ###   ########.fr       */
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
    ft_printf("freeing func activated\n");
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free (array);
    return(0);
}

int oneargcheck(char *array[])

{
    int i;
    int j;

    i = 0;
    //ft_printf("got here\n");
    //check for only ints
    //ft_printf("first string = %s\n", array[i]);
    while (array[i])
    {
        if (numcheck(array[i]) == 0)
            return (arrayfree(array));
        i++;
    }
    i = 0;
    //ft_printf("got here\n");
    //check for dupes
    while (array[i])
    {
        j = 1;
        while (array[i + j])
        {
            if (ft_strncmp(array[i], array[i + j], 12) == 0)
                return (arrayfree(array));
            j++;
        }
        i++;
    }
    //ft_printf("got here\n");
    //check for max/min int
    //ft_printf("ok here\n");
    i = 0;
    while (array[i])
    {
        if (ft_pushatoi(array[i]) > 2147483647 || ft_pushatoi(array[i]) < -2147483648)
            return (arrayfree(array));
        i++;
    }
    return (1);
}

int argcheck(int argc, char *argv[])

{
    int i;
    int j;

    i = 1;
    if (argc < 2)
        return (0);
    /* if (argc == 2)
    {
        char    **array;
        array = ft_split(argv[1], ' ');
        if (array[1] == NULL)
            return(arrayfree(array));
        //ft_printf("first string = %s\n", array[0]);
        return (oneargcheck(array));
    } */
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
            if (ft_strncmp(argv[i], argv[i + j], 12) == 0)
                return (0);
            j++;
        }
        i++;
    }
    //check for max/min int
    //ft_printf("ok here\n");
    i = 1;
    while (argv[i])
    {
        if (ft_pushatoi(argv[i]) > 2147483647 || ft_pushatoi(argv[i]) < -2147483648)
            return (0);
        i++;
    }
    return (1);
}