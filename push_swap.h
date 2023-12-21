/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:58:07 by clundber          #+#    #+#             */
/*   Updated: 2023/12/21 16:49:17 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int 	main(int argc, char *argv[]);
long    ft_pushatoi(const char *str);
int 	argcheck(int argc, char *argv[]);
int 	numcheck(char *str);
t_stack	*ps_lstlast(t_stack *lst);
t_stack	*ps_lstnew(int content);
void	ps_lstadd_back(t_stack **lst, t_stack *new);


//		swapping functions
t_stack	*swap_sasb(t_stack *stack_a);

#endif