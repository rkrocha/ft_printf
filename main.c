/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:25:29 by rkochhan          #+#    #+#             */
/*   Updated: 2020/12/27 10:43:30 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int ft_printf(const char *format, ...);
malloc, free, write, va_start, va_arg, va_copy, va_end
no buffer management , writes to stdout

%[parameter][flags][width][.precision][length]type
no parameter
		cspdiuxX%
flags	-0.*	minimum field width with all conversions

BONUS
conversions	nfge
some flags:	l ll h hh
all flags:	# " " +
*/

#include <stdio.h>

int	main(void)
{
	printf("%8.3f abc\n", 3.14159);
}
