/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:09:13 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/08 00:44:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	len_to_eol_two(t_buff **node, size_t *len)
{
	while ((*node)->next && !(*node)->eol)
	{
		*len += (*node)->len;
		*node = (*node)->next;
	}
}

size_t	len_to_eol(t_buff *buff)
{
	t_buff			*node;
	size_t			len;
	size_t			i;

	node = buff;
	len = 0;
	len_to_eol_two(&node, &len);
	if (node->eol)
	{
		i = 0;
		while (i < node->len)
		{
			if (node->buff[i] == '\n')
			{
				len += i;
				break ;
			}
			i++;
		}
	}
	else if (!node->next)
		len += node->len;
	return (len);
}

t_buff	*get_initial_buff(void)
{
	t_buff			*buff;

	buff = malloc(sizeof(t_buff));
	if (!buff)
		return (NULL);
	buff->eol = 0;
	buff->eof = 0;
	buff->len = 0;
	buff->next = NULL;
	return (buff);
}

char	get_eol(t_buff *buff)
{
	unsigned int	i;

	i = 0;
	while (i < buff->len)
	{
		if (buff->buff[i] == '\n')
		{
			buff->eol = 1;
			break ;
		}
		i++;
	}
	if (i == buff->len)
		return (0);
	return (1);
}
