/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:00:44 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:24:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f	v3f_mul(t_vec3f vec, float fac)
{
	return ((t_vec3f){vec.x * fac, vec.y * fac, vec.z * fac});
}
