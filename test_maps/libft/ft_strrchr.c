/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:02:26 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/12 10:15:23 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s);
	while (i >= j && s[i] != (char)c)
	{
		i--;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
	return (NULL);
}
