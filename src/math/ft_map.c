/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 01:59:14 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/08 18:27:15 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_mapf(float v, float source_min, float source_max, float dest_min, float dest_max)
{
	return (dest_min + ((dest_max - dest_min) / (source_max - source_min)) * (v - source_min));
}

int		ft_mapi(int v, int source_min, int source_max, int dest_min, int dest_max)
{
	return (dest_min + ((dest_max - dest_min) / (source_max - source_min)) * (v - source_min));
}
