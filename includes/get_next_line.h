/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:54:57 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/08 00:47:47 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <limits.h>

typedef struct s_buff
{
	char			buff[GNL_BUFFER_SIZE];
	size_t			len;
	char			eol;
	char			eof;
	struct s_buff	*next;
}					t_buff;

int			flush_to_eol(t_buff **buff, char **line);
t_buff		*clear_buff_next(t_buff *buff);
void		trim_buff(t_buff *buff, unsigned int nl);
int			flush_el(t_buff **buff, char **line);
t_buff		*get_initial_buff(void);
char		get_eol(t_buff *buff);
size_t		len_to_eol(t_buff *buff);

#endif
