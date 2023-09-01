/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:16:13 by jmanet            #+#    #+#             */
/*   Updated: 2022/05/30 09:20:14 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printformat(va_list args, char c)
{
	int	outputlen;

	outputlen = 0;
	if (c == 'c')
		outputlen = ft_printchar(va_arg(args, int));
	if (c == 's')
		outputlen = ft_printstr(va_arg(args, char *));
	if (c == 'p')
		outputlen = ft_printptr(va_arg(args, unsigned long));
	if (c == 'd')
		outputlen = ft_printnbr(va_arg(args, int));
	if (c == 'i')
		outputlen = ft_printnbr(va_arg(args, int));
	if (c == 'u')
		outputlen = ft_printunsigned(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		outputlen = ft_printhex(va_arg(args, unsigned int), c);
	if (c == '%')
		outputlen = ft_printchar('%');
	return (outputlen);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		outputlen;
	int		i;

	i = 0;
	outputlen = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			outputlen += ft_printformat(args, input[i + 1]);
			i++;
		}
		else
			outputlen += ft_printchar(input[i]);
		i++;
	}
	va_end(args);
	return (outputlen);
}
