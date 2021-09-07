/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 02:49:28 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:24:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	v3f_dist(t_vec3f vec1, t_vec3f vec2)
{
	const float		x_diff = (vec2.x - vec1.x) * (vec2.x - vec1.x);
	const float		y_diff = (vec2.y - vec1.y) * (vec2.y - vec1.y);
	const float		z_diff = (vec2.z - vec1.z) * (vec2.z - vec1.z);
	const float		sum = x_diff + y_diff + z_diff;

	return (sqrtf(sum));
}
