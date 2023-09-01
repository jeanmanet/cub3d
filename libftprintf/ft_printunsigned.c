/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:08:19 by jmanet            #+#    #+#             */
/*   Updated: 2022/05/30 09:10:41 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignedlen(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb > 9)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

void	ft_putunsigned(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunsigned(nb / 10);
		ft_putunsigned(nb % 10);
	}
	if (nb <= 9)
		ft_printchar(nb + '0');
}

int	ft_printunsigned(unsigned int nb)
{
	int	outputlen;

	outputlen = ft_unsignedlen(nb);
	ft_putunsigned(nb);
	return (outputlen);
}
