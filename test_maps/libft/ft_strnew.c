/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:53:53 by tbreart           #+#    #+#             */
/*   Updated: 2015/01/07 09:24:43 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	tmp = (char*)malloc(sizeof(*tmp) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < size + 1)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
