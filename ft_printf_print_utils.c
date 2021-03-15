/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:29:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 08:39:18 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**		From what I could gather, the most reasonable way to print most
**		conversions was to do so in the following order:
**
**	1. If there's no '-' flag, then pad with spaces according to given
**		precision or width. A sign (such as a negative sign) counts as
**		width but not as precision.
**
**	2. If the number to be printed is negative (or has any sign, or
**		space padding in case of ' ' flag), then print the sign.
**
**	3. If the specified precision value is larger or equal to the amount
**		of characters to print, or if the '0' flag is in play and width
**		is larger or equal to the amount of int digits to print, then
**		pad with zeroes.
**
**	4. If a number to be printed is zero, and there is a precision flag
**		and precision value is zero, then don't print anything. If number
**		is zero and width is also zero, then print a space. For all other
**		cases, print what there is to print.
**
**	5. If the conversion printed so far was left-justified ('-' flag),
**		then there may be space padding to print depending on width,
**		precision, and the amount of digits to print.
**
**		This is the logic used in the function prinft_print seen below.
**		All additional adjustments depend on the type of conversion, and
**		can be prepared before being sent to this function.
*/

void	printf_print(t_params conv, size_t len, bool zero, bool sign)
{
	if (!conv.flag_minus)
	{
		if ((size_t)conv.precision >= len)
			printf_pad(' ', conv.width - conv.precision - sign);
		else if (!conv.flag_zero)
			printf_pad(' ', conv.width - len);
	}
	if (sign)
		ft_putchar('-');
	if ((size_t)conv.precision >= len)
		printf_pad('0', conv.precision - len + sign);
	else if (conv.flag_zero && (size_t)conv.width > len)
		printf_pad('0', conv.width - len);
	if (!(zero && conv.flag_precision && conv.precision == 0))
		ft_putstr(conv.string);
	else if (zero && conv.width > 0)
		ft_putchar(' ');
	if (conv.flag_minus)
	{
		if ((size_t)conv.width > len && (size_t)conv.precision > len)
			printf_pad(' ', conv.width - conv.precision - sign);
		else if ((size_t)conv.width > len)
			printf_pad(' ', (size_t)conv.width - len);
	}
}

void	printf_pad(char c, int len)
{
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
}
