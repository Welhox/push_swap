/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welhox <welhox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:58:07 by clundber          #+#    #+#             */
/*   Updated: 2023/12/14 14:53:57 by welhox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H
# include <unistd.h>
# include <stdlib.h>

int main(int argc, char **argv);
int argcheck(int argc, char **argv);
int numcheck(char *str);



typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;



#endif