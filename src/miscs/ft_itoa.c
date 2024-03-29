/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:54:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 17:13:47 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(size_t powa, const char sign)
{
	size_t			len;

	len = powa;
	if (sign)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			sign;
	size_t			pow;
	char			*result;

	pow = ft_count_uint_base(n, 10);
	if (n >= 0)
		sign = 0;
	else
		sign = '-';
	result = ft_calloc(length(pow, sign) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (!sign)
		n = -n;
	while (pow)
	{
		result[length(pow, sign) - 1] = -(n % 10) + '0';
		pow--;
		n /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
