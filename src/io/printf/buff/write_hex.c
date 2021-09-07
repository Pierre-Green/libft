/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:30:38 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:04:37 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/buff.h"

static char	char_calc_uppercase(char uppercase, unsigned long int tmp)
{
	if (uppercase)
		return (tmp + 55);
	else
		return (tmp + 87);
}

size_t	buff_write_hex(t_buff *buff, unsigned long int n,
	char uppercase)
{
	char				t_buff[16];
	size_t				i;
	unsigned long int	tmp;

	i = 0;
	if (!n)
		return (buff_write_uchar(buff, '0'));
	while (n)
	{
		tmp = n % 16;
		if (tmp < 10)
			t_buff[i] = tmp + 48;
		else
			t_buff[i] = char_calc_uppercase(uppercase, tmp);
		i++;
		n /= 16;
	}
	tmp = i;
	while (tmp > 0)
	{
		buff_write_uchar(buff, t_buff[tmp - 1]);
		tmp--;
	}
	return (i);
}
