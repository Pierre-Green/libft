/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:03:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 19:18:19 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_arg		*get_arg(char *value)
{
	t_arg			*result;

	if (!(result = malloc(sizeof(t_arg))))
		return (NULL);
	result->next = 0;
	result->value = ft_strdup(value);
	return (result);
}

static t_args		*get_args(int argc)
{
	t_args			*result;

	if (!(result = malloc(sizeof(t_args))))
		return (NULL);
	result->args = 0;
	result->count = argc - 1;
	return (result);
}

t_args				*ft_args_start(int argc, char **argv)
{
	t_args			*args;
	t_arg			*node;
	size_t			i;

	if (!(args = get_args(argc)))
		return (NULL);
	while (i < argc)
	{
		if (!node)
		{
			if (!(node = get_arg(argv[i])))
				return (ft_args_end(&args));
			args->args = node;
		}
		else
		{
			if (!(node->next = get_arg(argv[i])))
				return (ft_args_end(&args));
			node = node->next;
		}
		i++;
	}
	return (args);
}