/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:06:55 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/19 10:34:14 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_get_size(int n)
{
	int				len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*tmp;
	int				a;
	int				b;

	b = ft_get_size(n);
	tmp = ft_strnew(b);
	a = 1;
	if (n < 0)
	{
		a = -1;
		tmp[0] = '-';
	}
	if (n == 0)
		tmp[0] = '0';
	if (b > 0)
		b = b - 1;
	while (n != 0)
	{
		tmp[b] = a * (n % 10) + '0';
		n = n / 10;
		b--;
	}
	return (tmp);
}
