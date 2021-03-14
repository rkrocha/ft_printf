/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 16:24:34 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_pad(char c, int len)
{
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
}

/*
**		From what I could gather, the most reasonable way to print all
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

void	printf_print(t_params conv, size_t len, bool is_zero, bool sign)
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
	if (!(is_zero && conv.flag_precision && conv.precision == 0))
		ft_putstr(conv.string);
	else if (is_zero && conv.width > 0)
		ft_putchar(' ');
	if (conv.flag_minus)
	{
		if ((size_t)conv.width > len && (size_t)conv.precision > len)
			printf_pad(' ', conv.width - conv.precision - sign);
		else if ((size_t)conv.width > len)
			printf_pad(' ', (size_t)conv.width - len);
	}
}

bool	printf_errors(t_params *conv)
{
	if ((*conv).width < 0)
	{
		(*conv).width *= -1;
		(*conv).flag_minus = true;
	}
	if ((*conv).flag_minus && (*conv).flag_zero && (*conv).specifier != '%')
	{
		return (true); // IS THIS SUPPOSED TO HAPPEN?
	}
	return (false);
}

void	get_width_preci(t_params *conv, va_list arg, char *sub_format)
{
	char	*width_ptr;
	char	*preci_ptr;

	preci_ptr = ft_strchr(sub_format, '.');
	if ((*conv).flag_star_width)
		(*conv).width = va_arg(arg, int);
	else
	{
		width_ptr = ft_strsearch(sub_format, "123456789");
		if (width_ptr && (!preci_ptr || width_ptr < preci_ptr))
			(*conv).width = ft_atoi(width_ptr);
	}
	if ((*conv).flag_star_preci)
		(*conv).precision = va_arg(arg, int);
	else if ((*conv).flag_precision)
		(*conv).precision = ft_atoi(preci_ptr + 1);
} 				// use atoll? ^

void	get_flags(t_params *conv, char *sub_format)
{
	char	*digit_ptr;
	char	*preci_ptr;
	char	*ptr;

	digit_ptr = ft_strsearch(sub_format, "123456789");
	if ((preci_ptr = ft_strchr(sub_format, '.')))
		(*conv).flag_precision = true;
	if ((ptr = ft_strchr(sub_format, '-')) && (!preci_ptr || ptr < preci_ptr))
		if (!digit_ptr || ptr < digit_ptr)
			(*conv).flag_minus = true;
	if ((ptr = ft_strchr(sub_format, '0')) && (!preci_ptr || ptr < preci_ptr))
		if (!digit_ptr || ptr < digit_ptr)
			(*conv).flag_zero = true;
	if ((ptr = ft_strchr(sub_format, '*')) && (!preci_ptr || ptr < preci_ptr))
		(*conv).flag_star_width = true;
	if (preci_ptr && (ptr = ft_strrchr(sub_format, '*')) && ptr > preci_ptr)
		(*conv).flag_star_preci = true;
}

bool	copy_conversion(const char *format, t_params *conv, int *i)
{
	const char	*start;
	const char	*end;

	start = &format[*i];
	if ((end = ft_strsearch(start, PRINTF_SPECS)))
	{
		if (end == ft_strignore(start, PRINTF_VALID))
		{
			(*conv).sub_format = ft_substr(start, 0, end - start + 1);
			(*conv).specifier = *end;
			*i += end - start + 1;
			return (true);
		}
	}
	return (false);
}
