/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_lst_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 05:44:43 by tbreart           #+#    #+#             */
/*   Updated: 2015/01/08 16:16:03 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_del_lst_elem(t_list *first)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = first;
	while (tmp != NULL)
	{
		free(tmp->content);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}
