/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 01:59:14 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:23:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
