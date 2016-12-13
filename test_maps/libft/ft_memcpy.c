/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:00:50 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/15 16:10:36 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	char			*tmp2;

	i = 0;
	tmp1 = (unsigned char*)dest;
	tmp2 = (char*)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dest);
}
