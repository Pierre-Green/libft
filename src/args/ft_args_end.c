/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:15:34 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 19:17:48 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_args				*ft_args_end(t_args **args)
{
	t_arg			*node;
	t_arg			*tmp;

	node = (*args)->args;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->value);
		free(tmp);
	}
	free((*args));
	*args = NULL;
	return (*args);
}
