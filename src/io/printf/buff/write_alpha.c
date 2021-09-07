/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:26:00 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:01:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/buff.h"

size_t	buff_write_uchar(t_buff *buff, unsigned char c)
{
	buff_flush_if_full(buff);
	buff->buff[buff->len] = c;
	buff->len++;
	buff_flush_if_full(buff);
	return (1);
}

size_t	buff_write_nchar(t_buff *buff, size_t count, unsigned char c)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		buff_write_uchar(buff, c);
		i++;
	}
	return (i);
}

size_t	buff_write_strl(t_buff *buff, char *s, size_t len)
{
	uint32_t	i;

	i = 0;
	while (i < len && buff->len != BUFF_SIZE)
	{
		buff->buff[buff->len] = *(s + i);
		buff->len++;
		i++;
	}
	if (buff->len == BUFF_SIZE)
	{
		buff_flush(buff);
		buff_write_strl(buff, s + i, len - i);
	}
	return (len);
}

size_t	buff_write_str(t_buff *buff, char *s)
{
	uint32_t	i;

	i = 0;
	while (s[i])
		i++;
	buff_write_strl(buff, s, i);
	return (i);
}
