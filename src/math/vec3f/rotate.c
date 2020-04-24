/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:50:54 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/24 20:56:18 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f		ft_vec3f_rotx(t_vec3f vec, float x)
{
	vec.y = vec.y * cos(x) - vec.z * sin(x);
	vec.z = vec.y * sin(x) + vec.z * cos(x);
    return (vec);
}

t_vec3f		ft_vec3f_roty(t_vec3f vec, float y)
{
	vec.x = vec.x * cos(y) + vec.z * sin(y);
	vec.z = vec.x * -sin(y) + vec.z * cos(y);
    return (vec);
}

t_vec3f		ft_vec3f_rotz(t_vec3f vec, float z)
{
	vec.x = vec.x * cos(z) - vec.y * sin(z);
	vec.y = vec.x * sin(z) + vec.y * cos(z);
    return (vec);
}

t_vec3f		ft_vec3f_rot(t_vec3f vec, t_vec3f angle)
{
	vec = ft_vec3f_rotx(vec, angle.x);
	vec = ft_vec3f_roty(vec, angle.y);
	vec = ft_vec3f_rotz(vec, angle.z);
    return (vec);
}