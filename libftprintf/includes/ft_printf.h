/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:56 by jmanet            #+#    #+#             */
/*   Updated: 2022/05/30 09:21:37 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *input, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int nb);
int	ft_printhex(unsigned int nb, char c);
int	ft_printptr(unsigned long nb);
int	ft_printunsigned(unsigned int nb);

#endif
