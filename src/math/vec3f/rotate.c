/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:50:54 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:24:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f	v3f_rotx(t_vec3f vec, float x)
{
	vec.y = vec.y * cos(x) - vec.z * sin(x);
	vec.z = vec.y * sin(x) + vec.z * cos(x);
	return (vec);
}

t_vec3f	v3f_roty(t_vec3f vec, float y)
{
	vec.x = vec.x * cos(y) + vec.z * sin(y);
	vec.z = vec.x * -sin(y) + vec.z * cos(y);
	return (vec);
}

t_vec3f	v3f_rotz(t_vec3f vec, float z)
{
	vec.x = vec.x * cos(z) - vec.y * sin(z);
	vec.y = vec.x * sin(z) + vec.y * cos(z);
	return (vec);
}

t_vec3f	v3f_rot(t_vec3f vec, t_vec3f angle)
{
	vec = v3f_rotx(vec, fdeg2rad(angle.x * 360.0f));
	vec = v3f_roty(vec, fdeg2rad(angle.y * 360.0f));
	vec = v3f_rotz(vec, fdeg2rad(angle.z * 360.0f));
	return (vec);
}
