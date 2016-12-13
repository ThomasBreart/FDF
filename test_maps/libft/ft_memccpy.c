/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:18:18 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/19 14:47:33 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*tmp1;
	char		*tmp2;
	size_t		i;

	i = 0;
	tmp1 = (char*)dst;
	tmp2 = (char*)src;
	while (i < n)
	{
		if (tmp2[i] == c)
		{
			tmp1[i] = tmp2[i];
			return (dst + i + 1);
		}
		tmp1[i] = tmp2[i];
		i++;
	}
	return (NULL);
}
