# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 11:59:53 by clundber          #+#    #+#              #
#    Updated: 2024/02/07 15:03:35 by clundber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------ PROJECT -------#
NAME = push_swap
LIBFTNAME = libft.a
# ------------ DIRECTORIES ---#
LIBFT_DIR = ./libft

#------------- SOURCE FILES ------#
CFILES = push_swap.c ps_argument.c ps_lst.c ps_swap_functions.c ps_swap_functions2.c \
	ps_algo.c ps_sort_utils.c ps_sort_utils2.c ps_push.c

OFILES = $(CFILES:.c=.o)

#--------- FLAGS ----------#

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I includes

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT_DIR)/$(LIBFTNAME) -o $(NAME)
	
clean:
	rm -f $(OFILES) 
	@make clean -C libft/

fclean: clean
	rm -f $(NAME) 
	@rm -f libft/libft.a

re: fclean $(NAME) 

.PHONY: all clean fclean re