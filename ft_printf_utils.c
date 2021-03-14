/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 09:55:07 by rkochhan         ###   ########.fr       */
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
}

void	get_flags(t_params *conv, char *sub_format)
{
	char	*ptr;

	ptr = sub_format;
	while ((ptr = ft_strsearch(ptr, PRINTF_FLAGS)))
	{
		if (!(*conv).flag_precision && *ptr == '-')
			(*conv).flag_minus = true;
		if (!(*conv).flag_precision && *ptr == '0')
		{
			if (ptr == &sub_format[0])
				(*conv).flag_zero = true;
			else if ((ptr > &sub_format[0] && !ft_isdigit(*(ptr - 1))))
				(*conv).flag_zero = true;
		}
		if (!(*conv).flag_precision && *ptr == '.')
			(*conv).flag_precision = true;
		if (*ptr == '*')
		{
			if (ptr > &sub_format[0] && *(ptr - 1) == '.')
				(*conv).flag_star_preci = true;
			else
				(*conv).flag_star_width = true;
		}
		ptr += 1;
	}
}
// REMAKE v
bool	copy_conversion(const char *format, t_params *conv, int *i)
{
	int	j;

	j = 0;
	while (j < 23 && format[*i] && ft_strchr(PRINTF_CONVERSION, format[*i]))
	{
		(*conv).sub_format[j] = format[*i];
		(*i)++;
		j++;
		if (ft_strchr(PRINTF_SPECS, (*conv).sub_format[j - 1]))
		{
			(*conv).specifier = (*conv).sub_format[j - 1];
			return (true);
		}
	}
	return (false);
}
