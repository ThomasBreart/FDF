/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:51:39 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/14 19:31:51 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (s != NULL && f != NULL)
	{
		tmp = ft_strnew(ft_strlen(s));
		while (s[i] != '\0')
		{
			tmp[i] = f(i, s[i]);
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
