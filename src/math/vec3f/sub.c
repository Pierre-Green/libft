/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:59:40 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:24:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f	v3f_sub(t_vec3f vec1, t_vec3f vec2)
{
	return ((t_vec3f){vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z});
}
