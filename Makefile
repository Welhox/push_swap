# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welhox <welhox@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 11:59:53 by clundber          #+#    #+#              #
#    Updated: 2023/12/14 15:58:09 by welhox           ###   ########.fr        #
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

CFILES = push_swap.c

OFILES = $(CFILES:.c=.o)


#--------- FLAGS ----------

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft
	ar rcs $(NAME) $(OFILES) $(LIBFT_DIR)/$(LIBFTNAME)
#	$(CC) $(CFLAGS) $(NAME) $(OFILES) $(LIBFT_DIR)/$(LIBFTNAME)
clean:
	rm -f $(OFILES) 
	@make clean -C libft/

fclean: clean
	rm -f $(NAME) 
	@make fclean -C libft

re: fclean $(NAME) 

.PHONY: all clean fclean re