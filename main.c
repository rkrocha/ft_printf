/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:04:03 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/09 12:41:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int ft_printf(const char *format, ...);
malloc, free, write, va_start, va_arg, va_copy, va_end
no buffer management , writes to stdout

%[flags][width][.precision][length]type

types
	c: char
	s: string
	p: ptr addr
	d: signed decimal int
	i: signed decimal int
	u: unsigned decimal int
	x: unsigned hexadecimal int
	X: unsigned hexadecimal int (capital letters)
	%: char

flags
	-: left-justify within the given field width. Right justification is the
default (see width sub-specifier).
	0: left-pads the number with zeroes instead of spaces, where padding is
	specified (see width sub-specifier).
	*: The width is not specified in the format string, but as an additional
integer value argument preceding the argument that has to be formatted.

width
	number: minimum number of characters to be printed. If the value to be
printed is shorter than this number, the result is padded with blank spaces.
The value is not truncated even if the result is larger.


minimum field width with all conversions


BONUS
types
	n: nothing printed
	f: decimal floating point
	g: shorter of %e or %f
	e: scientific notation (mantissa/exponent) using 'e' character

some flags:	l ll h hh
all flags:	# " " +
*/

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	ft_printf("abc %5d ft\n", 3);
	printf("abc %5d def\n\n", 3);

	ft_printf("abc %.5d ft\n", 3);
	printf("abc %.5d def\n\n", 3);

	ft_printf("abc %-5d ft\n", 3);
	printf("abc %-5d def\n\n", 3);

	ft_printf("abc %05d ft\n", 3);
	printf("abc %05d def\n\n", 3);

	ft_printf("abc %-6.3d ft\n", 3);
	printf("abc %-6.3d def\n\n", 3);

	ft_printf("abc %-3.6d ft\n", 3);
	printf("abc %-3.6d def\n\n", 3);

	ft_printf("abc %-3.3d ft\n", 3);
	printf("abc %-3.3d def\n\n", 3);

	ft_printf("abc %3d ft\n", 33333);
	printf("abc %3d def\n\n", 33333);

	ft_printf("abc %.3d ft\n", 33333);
	printf("abc %.3d def\n\n", 33333);

	ft_printf("abc %-3d ft\n", 33333);
	printf("abc %-3d def\n\n", 33333);

	ft_printf("abc %03d ft\n", 33333);
	printf("abc %03d def\n\n", 33333);
}
