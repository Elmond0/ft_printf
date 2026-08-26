/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_utils1.c                                 :+:      :+:    :+:   */
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

void	test_char(void)
{
	int	r1;
	int	r2;

	r1 = ft_printf("ft : [%c]\n", 'A');
	r2 = printf("std: [%c]\n", 'A');
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
}

void	test_str(void)
{
	int	r1;
	int	r2;

	r1 = ft_printf("ft : [%s]\n", "hello 42");
	r2 = printf("std: [%s]\n", "hello 42");
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
	r1 = ft_printf("ft : [%s]\n", (char *)0);
	r2 = printf("std: [%s]\n", "(null)");
	ft_printf("ret -> ft: %d | std: %d\n\n", r1, r2);
}
