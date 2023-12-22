# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clundber <clundber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 11:59:53 by clundber          #+#    #+#              #
#    Updated: 2023/12/22 15:06:03 by clundber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------ PROJECT -------#
NAME = push_swap.a
LIBFTNAME = libft.a
# ------------ DIRECTORIES ---#
LIBFT_DIR = ./libft
#SRC_DIR = srcs
#LIBFT_DIR = libft/includes
##FT_PRINTF_DIR = srcs/ft_printf
#GNL_DIR = srcs/get_next_line

#------------- SOURCE FILES ------#

#SRC_FLS = $(LIBFT_FLS) $(FT_PRINTF_FLS) $(GNL_FLS)

CFILES = push_swap.c push_swap_argcheck.c push_swap_lst.c ps_sortfunc.c

OFILES = $(CFILES:.c=.o)


#--------- FLAGS ----------

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I includes

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT_DIR)/$(LIBFTNAME) -o $(NAME)
#	ar rcs $(NAME) $(OFILES) 
#	$(LIBFT_DIR)/$(LIBFTNAME)
	
	
clean:
	rm -f $(OFILES) 
	@make clean -C libft/

fclean: clean
	rm -f $(NAME) 
	@make fclean -C libft

re: fclean $(NAME) 

.PHONY: all clean fclean re