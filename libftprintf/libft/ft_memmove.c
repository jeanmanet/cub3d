/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:36:40 by jmanet            #+#    #+#             */
/*   Updated: 2022/04/20 11:00:30 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
	{
		while (i < n)
		{		
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
