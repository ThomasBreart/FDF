/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:42:10 by tbreart           #+#    #+#             */
/*   Updated: 2015/04/17 14:11:10 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_get_word(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

static char		*ft_cpy_word(char const *s, char c)
{
	int		a;
	char	*tmp;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a] != c && s[a] != '\0')
		a++;
	tmp = ft_strsub(s, 0, a);
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;
	int		t;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	t = ft_get_word(s, c);
	str = (char**)malloc(sizeof(char*) * t + 1);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			str[j] = ft_cpy_word(&s[i], c);
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
