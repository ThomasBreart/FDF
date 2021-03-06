/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:20:48 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/19 09:46:19 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*tmp;

	i = 0;
	if (s == NULL)
		return (NULL);
	tmp = s;
	while (tmp[i] != (char)c && i < n)
		i++;
	if (i < n && tmp[i] == (char)c)
		return ((void*)(s + i));
	return (NULL);
}
