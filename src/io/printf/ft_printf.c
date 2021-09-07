/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:19:13 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:17:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/fmt.h"

static t_state	*get_initial_state(const char *format, va_list args)
{
	t_state		*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	state->count = 0;
	state->frmt = (char *)format;
	va_copy(state->args, args);
	state->buff = (t_buff *)malloc(sizeof(t_buff));
	if (!state->buff)
	{
		clear_state(state);
		return (NULL);
	}
	state->buff->len = 0;
	return (state);
}

int	ft_printf_va(const char *format, va_list args)
{
	t_state		*state;
	size_t		count;

	state = get_initial_state(format, args);
	if (!state)
		return (-42);
	while (*state->frmt)
	{
		if (*state->frmt == '%')
			fmt(state);
		else
		{
			while (*state->frmt && *state->frmt != '%')
			{
				state->count += buff_write_uchar(state->buff,
						(unsigned char)*state->frmt);
				state->frmt++;
			}
		}
	}
	buff_flush(state->buff);
	count = state->count;
	clear_state(state);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_printf_va(format, args);
	va_end(args);
	return (result);
}
