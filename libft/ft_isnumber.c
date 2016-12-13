/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 14:12:50 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/13 14:16:08 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isnumber(int c)
{
	if ((c >= 48 && c <= 57) || c == '-' || c == '+')
		return (1);
	return (0);
}
