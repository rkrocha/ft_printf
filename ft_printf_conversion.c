/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 11:07:29 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	printf_errors(t_params *conv)
{
	if ((*conv).width < 0)
	{
		(*conv).width *= -1;
		(*conv).flag_minus = true;
	}
	// if ((*conv).flag_minus && (*conv).flag_zero && (*conv).specifier != '%')
	// {
	// 	return (true); // IS THIS SUPPOSED TO HAPPEN?
	// }
	return (false);
}

void	printf_wid_preci(t_params *conv, va_list arg, char *sub_format)
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
}

void	printf_get_flags(t_params *conv, char *sub_format)
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
		(*conv).flag_star_preci = true;	// should it be ptr == preci_ptr + 1? ^
}

bool	printf_copy_conv(const char *format, t_params *conv, int *i)
{
	const char	*start;
	const char	*end;

	start = &format[*i];
	if ((end = ft_strsearch(start, PRINTF_SPECS)))
	{
		if (end - start + 1 < SUB_FORMAT_LEN)
		{
			if (end == ft_strignore(start, PRINTF_VALID))
			{
				ft_memccpy((*conv).sub_format, start, *end, SUB_FORMAT_LEN - 1);
				(*conv).specifier = *end; // check conversions ^
				*i += end - start + 1;
				return (true);
			}
		}
	}
	return (false);
}
