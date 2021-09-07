/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:39:12 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:20:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				lenght;
	t_list			*node;

	lenght = 0;
	node = lst;
	while (node)
	{
		lenght++;
		node = node->next;
	}
	return (lenght);
}
