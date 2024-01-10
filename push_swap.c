/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:29 by welhox            #+#    #+#             */
/*   Updated: 2024/01/10 16:38:45 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack **stack)

{
	t_stack	*ptr;
	int		i;

	if (*stack)
	{
		ptr = NULL;
		i = 1;
		ptr = (*stack);
		ptr->index = 0;
		while (ptr->next)
		{
			ptr = ptr->next;
			ptr->index = i;
			i++;
		}
	}
}

int	ft_makelist(char *argv[], t_stack **stack_a, int argc)

{
	int	i;
	int	number;

	number = 0;
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (ps_lstadd_back(stack_a, ps_lstnew(number)) == 0)
		{
			lst_clear(stack_a);
			arrayfree(argv);
			write(2, "malloc failed\n", 14);
			exit(0);
		}
		i++;
	}
	ft_index(stack_a);
	return (1);
}

int	ft_sorted(t_stack **stack_a, t_stack **stack_b)

{
	t_stack	*ptr;

	ptr = NULL;
	ptr = (*stack_a);
	if (*stack_a && !*stack_b)
	{
		while (ptr->next)
		{
			if (ptr->content > ptr->next->content)
				return (0);
			ptr = ptr->next;
		}
		return (1);
	}
	return (0);
}

void	lst_clear(t_stack **stack)

{
	t_stack	*ptr;
	t_stack	*ptr2;

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

int	main(int argc, char *argv[])

{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argcheck(argc, argv) == 0)
		ft_error(argv, argc);
	if ((argv[1] == NULL || argv[0] == NULL) && argc == 2)
		return (arrayfree(argv));
	if (ft_makelist(argv, &stack_a, argc) == 0)
		return (0);
	if (argc == 2)
		arrayfree(argv);
	algo_control(&stack_a, &stack_b);
	lst_clear(&stack_a);
	lst_clear(&stack_b);
	return (0);
}
