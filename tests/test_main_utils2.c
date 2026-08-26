/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test_main.h"
#include <stdio.h>

void	test_int(void)
{
	int	r1;
	int	r2;

	r1 = ft_printf("ft : [%d]\n", -42);
	r2 = printf("std: [%d]\n", -42);
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
	r1 = ft_printf("ft : [%i]\n", 2147483647);
	r2 = printf("std: [%i]\n", 2147483647);
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
}

void	test_uint_hex(void)
{
	int	r1;
	int	r2;

	r1 = ft_printf("ft : [%u]\n", 4294967295u);
	r2 = printf("std: [%u]\n", 4294967295u);
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
	r1 = ft_printf("ft : [%x] [%X]\n", 255, 255);
	r2 = printf("std: [%x] [%X]\n", 255, 255);
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
}

void	test_ptr_percent(void)
{
	int	n;
	int	r1;
	int	r2;

	n = 42;
	r1 = ft_printf("ft : [%p]\n", &n);
	r2 = printf("std: [%p]\n", &n);
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
	r1 = ft_printf("ft : [%%]\n");
	r2 = printf("std: [%%]\n");
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
}
