/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welhox <welhox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:58:07 by clundber          #+#    #+#             */
/*   Updated: 2024/01/02 15:50:55 by welhox           ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
}	t_stack;

long    ft_pushatoi(const char *str);
int 	argcheck(int argc, char *argv[]);
int 	numcheck(char *str);
t_stack	*ps_lstlast(t_stack *lst);
t_stack	*ps_lstnew(int content);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
int    	arrayfree(char **array);
int 	oneargcheck(char **array);

//		swapping functions
t_stack	*swap_sasb(t_stack **stack_a);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	swap_pb(t_stack **stack_a, t_stack **stack_b);
#endif