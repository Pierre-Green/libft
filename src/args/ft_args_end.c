/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:15:34 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 17:57:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_args	*ft_args_end(t_args **args)
{
	unsigned int	i;

	i = 0;
	while (i < (*args)->count)
	{
		free((void *)(*args)->args[i]);
		i++;
	}
	free((*args));
	*args = NULL;
	return (*args);
}
