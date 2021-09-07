/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:51:36 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 18:16:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/state.h"

void	clear_state(t_state *state)
{
	if (state->buff)
		free((void *)state->buff);
	state->buff = NULL;
	state->frmt = NULL;
	free((void *)state);
}
