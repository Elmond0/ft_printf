/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test_main.h"

int	main(void)
{
	ft_printf("=== %%c ===\n");
	test_char();
	ft_printf("=== %%s ===\n");
	test_str();
	ft_printf("=== %%d / %%i ===\n");
	test_int();
	ft_printf("=== %%u / %%x / %%X ===\n");
	test_uint_hex();
	ft_printf("=== %%p / %%%% ===\n");
	test_ptr_percent();
	return (0);
}
