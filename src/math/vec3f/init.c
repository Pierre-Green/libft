/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:59:02 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:25:23 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f	v3f_init(float x, float y, float z)
{
	return ((t_vec3f){x, y, z});
}

t_vec3f	v3f_init1(float a)
{
	return (v3f_init(a, a, a));
}
