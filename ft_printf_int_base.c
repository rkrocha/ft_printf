/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:53:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 08:33:04 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	printf_int_errors(t_params *conv, int *nprint)
{
	if ((*conv).flag_minus && (*conv).flag_zero) // common errors?
	{
		*nprint = -1; // error message? check for %u errors
		return (true);
	}
	if ((*conv).flag_zero && (*conv).precision > 0) // common errors?
		(*conv).flag_zero = false;
	if ((*conv).precision < 0)
	{
		(*conv).flag_precision = false; // printf errors?
		(*conv).precision = 0;
	}
	return (false);
}

void		printf_int(t_params *conv, va_list ap, int *nprint)
{
	long	num;
	bool	sign;
	bool	is_zero;

	if (printf_int_errors(conv, nprint))
		return ;
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		num = (long)va_arg(ap, int);
	else
		num = (long)va_arg(ap, unsigned int);
	sign = false;
	if (num < 0)
	{
		num *= -1;
		sign = true;
	}
	is_zero = false;
	if (num == 0)
		is_zero = true;
	(*conv).string = ft_ullitoa_base(num, DECIMAL_BASE, false);
	printf_print(*conv, ft_strlen((*conv).string) + sign, is_zero, sign);
	*nprint += 1;
}

void		printf_hex(t_params *conv, va_list ap, int *nprint)
{
	unsigned int	num;
	bool			is_zero;

	is_zero = false;
	if (printf_int_errors(conv, nprint))
		return ;
	num = va_arg(ap, unsigned int);
	if (num == 0)
		is_zero = true;
	if ((*conv).specifier == 'x')
		(*conv).string = ft_ullitoa_base(num, LOWER_HEX_BASE, false);
	else
		(*conv).string = ft_ullitoa_base(num, UPPER_HEX_BASE, false);
	printf_print(*conv, ft_strlen((*conv).string), is_zero, false);
	ft_strdel(&(*conv).string);
	*nprint += 1; // FIX
}

void		printf_ptr(t_params *conv, va_list ap, int *nprint)
{
	unsigned long	num;
	char			*temp;

	if ((*conv).flag_zero && (*conv).precision > 0) // common errors?
		(*conv).flag_zero = false;

	num = va_arg(ap, unsigned long);
	if (num == 0 && (*conv).flag_precision && (*conv).precision == 0)
		(*conv).string = ft_strdup("0x");
	else
	{
		temp = ft_ullitoa_base(num, LOWER_HEX_BASE, false);
		(*conv).string = ft_strjoin("0x", temp);
		ft_strdel(&temp);
	}
	printf_print(*conv, ft_strlen((*conv).string), false, false);
	ft_strdel(&(*conv).string);
	*nprint += 1; // FIX
}
