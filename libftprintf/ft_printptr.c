/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 08:53:00 by jmanet            #+#    #+#             */
/*   Updated: 2022/04/06 09:59:09 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	if (ptr < 16)
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		if (ptr > 9)
			ft_printchar((ptr - 10) + 'a');
	}
}

int	ft_printptr(unsigned long ptr)
{
	int	outputlen;

	ft_printstr("0x");
	outputlen = 2;
	ft_putptr(ptr);
	if (ptr == 0)
		outputlen++;
	while (ptr >= 1)
	{
		outputlen++;
		ptr = ptr / 16;
	}
	return (outputlen);
}
