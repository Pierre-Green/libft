/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:05:32 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 17:55:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "limits.h"

void	printf_assert(char const *name, char const *format, ...);

void	test_static(void);

void	test_fmt_char(void);
void	test_fmt_str(void);
void	test_fmt_ptr(void);
void	test_fmt_int(void);
void	test_fmt_uint(void);
void	test_fmt_hex(void);
void	test_fmt_poly(void);

#endif
