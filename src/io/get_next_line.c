/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:49:24 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/08 00:45:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_do_buff_two(t_buff **node)
{
	while ((*node)->len && (*node)->next && (*node)->next->len)
		*node = (*node)->next;
	if ((*node)->len)
	{
		(*node)->next = get_initial_buff();
		if (!(*node)->next)
			return (-1);
		*node = (*node)->next;
	}
	return (0);
}

static int	read_do_buff(t_buff *buff, int fd, char **line, int score)
{
	int				read_ret;
	t_buff			*node;
	char			eol;

	node = buff;
	if (read_do_buff_two(&node) == -1)
		return (-1);
	read_ret = read(fd, node->buff, GNL_BUFFER_SIZE);
	if (read_ret >= 0)
	{
		if (read_ret == 0)
		{
			node->eof = 1;
			return (score);
		}
		score += (node->len = read_ret);
		eol = get_eol(node);
		if (eol >= 0 && read_ret < GNL_BUFFER_SIZE)
			node->eof = 1;
		else if (!eol)
			return ((score = read_do_buff(node, fd, line, score)));
	}
	return (score);
}

static int	get_next_line_two(t_buff **buff, int fd)
{
	buff[fd] = get_initial_buff();
	if (!buff[fd])
		return (-1);
	return (0);
}

static int	get_next_line_three(int *read_ret, t_buff **buff, int fd,
	char ***line)
{
	*read_ret = read_do_buff(buff[fd], fd, *line, 0);
	if (*read_ret > 0 || buff[fd]->len != 0)
		return (flush_to_eol(&(buff[fd]), *line));
	if (*read_ret == 0)
		flush_el(&(buff[fd]), *line);
	if (*read_ret == 0)
		return (0);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static t_buff	*buff[1024];
	t_buff			*ptr;
	int				read_ret;

	if (read(fd, NULL, 0) < 0 || GNL_BUFFER_SIZE == 0 || !line)
		return (-1);
	ptr = buff[fd];
	if (ptr)
	{
		while (ptr)
		{
			if ((ptr->buff[0] == '\n' && !ptr->eol && ptr->len)
				|| (ptr->eof && !ptr->len))
				return (flush_el(&(buff[fd]), line));
			else if (ptr->eol || (ptr->eof && ptr->len))
				return (flush_to_eol(&(buff[fd]), line));
			ptr = ptr->next;
		}
	}
	else if (get_next_line_two(buff, fd) == -1)
		return (-1);
	return (get_next_line_three(&read_ret, buff, fd, &line));
}
