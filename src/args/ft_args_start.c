/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:03:58 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 17:58:53 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_args	*get_args(int argc)
{
	t_args			*result;

	result = malloc(sizeof(t_args));
	if (result == NULL)
		return (NULL);
	result->args = malloc(sizeof(char *) * argc);
	if (result->args == NULL)
		return (NULL);
	result->args[argc] = 0;
	result->count = argc - 1;
	return (result);
}

t_args	*ft_args_start(int argc, char **argv)
{
	t_args			*args;
	size_t			i;

	args = get_args(argc);
	if (args == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)argc - 1)
	{
		args->args[i] = argv[i + 1];
		i++;
	}
	return (args);
}
