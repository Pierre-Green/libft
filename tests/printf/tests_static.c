/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_static.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:06:36 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/07 17:56:40 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_static(void)
{
	printf_assert("Static 1", "Hello i'm just like you");
	printf_assert("Static 2", "");
	printf_assert("Static 3", "|%5%|");
	printf_assert("Static 4", "|%-10%|");
	printf_assert("Static 5", "|%010%|");
	printf_assert("Static 6", "|%.-5%|");
	printf_assert("Static 7", "|%.5%|");
	printf_assert("Static 8", "|%.5%|");
}
