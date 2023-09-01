/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:43:29 by jmanet            #+#    #+#             */
/*   Updated: 2022/05/30 09:07:38 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb >= 1)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int nb, char c)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, c);
		ft_puthex(nb % 16, c);
	}
	if (nb < 16)
	{
		if (nb <= 9)
			ft_printchar(nb + '0');
		if (nb > 9)
		{
			if (c == 'x')
				ft_printchar((nb - 10) + 'a');
			if (c == 'X')
				ft_printchar((nb - 10) + 'A');
		}
	}
}

int	ft_printhex(unsigned int nb, char c)
{
	int	outputlen;

	outputlen = ft_hexlen(nb);
	ft_puthex(nb, c);
	return (outputlen);
}
