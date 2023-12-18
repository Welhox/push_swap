/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:09:04 by clundber          #+#    #+#             */
/*   Updated: 2023/11/17 16:33:48 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_printhex(unsigned long nbr, int caps);
int	ft_putnbr_return(int n);
int	ft_putstr_return(char *s);
int	ft_putchar_return(char c);
int	ft_putnbr_u_return(unsigned int nbr);

#endif