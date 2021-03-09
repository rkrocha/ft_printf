/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:53:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/09 09:03:33 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
`0' (zero)   Zero padding.  For all conversions except n, the converted value
is padded on the left with zeros rather than blanks.  If a precision is given
with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.

`-' A negative field width flag; the converted value is to be left adjusted
on the field boundary.  Except for n conversions, the converted value is padded
on the right with blanks, rather than on the left with blanks or zeros.
A - overrides a 0 if both are given.

o   An optional decimal digit string specifying a minimum field width.
If the converted value has fewer characters than the field width, it will be
padded with spaces on the left (or right, if the left-adjustment flag has been
given) to fill out the field width.

o   An optional precision, in the form of a period . followed by an optional
digit string.  If the digit string is omitted, the precision is taken as zero.
This gives the minimum number of digits to appear for d, i, o, u, x, and X
conversions, the number of digits to appear after the decimal-point for a, A, e, E, f, and F conversions, the maximum number of significant digits for g and G
conversions, or the maximum number of characters to be printed from a string
for s conversions.

error: flag '0' is ignored when flag '-' is present [-Werror,-Wformat]
error: '0' flag ignored with precision and ‘%d’ gnu_printf format [-Werror=format=]

printf("abc %5d def\n", 3);
printf("abc %.5d def\n", 3);
printf("abc %-5d def\n", 3);
printf("abc %05d def\n\n", 3);
abc     3 def
abc 00003 def
abc 3     def
abc 00003 def

printf("abc %-6.3d def\n", 3);
printf("abc %06.3d def\n", 3);
printf("abc %-3.6d def\n", 3);
printf("abc %03.6d def\n\n", 3);
abc 003    def
abc    003 def
abc 000003 def
abc 000003 def

printf("abc %3d def\n", 33333);
printf("abc %.3d def\n", 33333);
printf("abc %-3d def\n", 33333);
printf("abc %03d def\n\n", 33333);
abc 33333 def
abc 33333 def
abc 33333 def
abc 33333 def
*/

static void		printf_int_format(t_params *conv, char *arg, char **print)

static size_t	printf_int_alloc(t_params *conv, char *arg, char **print)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((*conv).width > len)
		len = (*conv).width;
	else if ((*conv).precision > len)
		len = (*conv).precision;
	*print = (char *)malloc((len + 1) * sizeof(char));
	return (len);
}

static bool		printf_int_errors(t_params *conv, int *nprint)
{
	if ((*conv).flag_minus && (*conv).flag_zero)
	{
		*nprint = -1;
		return (true);
	}
	if ((*conv).flag_zero && (*conv).precision)
		(*conv).flag_zero = false;
	return (false);
}

void		printf_int(t_params *conv, va_list ap, int *nprint)
{
	char	*arg;
	char	*print;
	size_t	len;

	if (printf_int_errors(conv, nprint))
		return ;
	arg = ft_itoa(va_arg(ap, int));
	len = printf_int_alloc(conv, arg, &print);
	if (!print)
	{
		ft_strdel(&arg);
		*nprint = -1
		return ;
	}
	*nprint += len;
	ft_putstr(print);
	ft_strdel(&print);
	ft_strdel(&arg);
}
