/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:00:44 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/25 19:09:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f				ft_vec3f_mul(t_vec3f vec, float fac)
{
	return ((t_vec3f){ vec.x * fac, vec.y * fac, vec.z * fac });
}