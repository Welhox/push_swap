/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_argcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:55:44 by clundber          #+#    #+#             */
/*   Updated: 2023/12/20 15:34:28 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_pushatoi(const char *str)

{
	long int	num;
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