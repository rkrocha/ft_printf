/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:53:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 17:44:05 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_int_adjust(t_params *conv)
{
	if ((*conv).flag_minus && (*conv).flag_zero)
		(*conv).flag_zero = false;
	if ((*conv).flag_zero && (*conv).flag_precision && (*conv).precision >= 0)
		(*conv).flag_zero = false;
	if ((*conv).precision < 0)
	{
		(*conv).flag_precision = false;
		(*conv).precision = 0;
	}
}

void		printf_int(t_params *conv, va_list ap, int *nprint)
{
	long	num;
	bool	sign;
	bool	is_zero;

	printf_int_adjust(conv);
	is_zero = false;
	sign = false;
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		num = (long)va_arg(ap, int);
	else
		num = (long)va_arg(ap, unsigned int);
	if (num < 0)
	{
		num *= -1;
		sign = true;
	}
	if (num == 0)
		is_zero = true;
	(*conv).string = ft_ullitoa_base(num, DECIMAL_BASE, false);
	if ((*conv).string && ((*conv).len = ft_strlen((*conv).string) + sign))
		printf_print(*conv, nprint, is_zero, sign);
	else
		*nprint = -1;
	ft_strdel(&(*conv).string);
}

void		printf_hex(t_params *conv, va_list ap, int *nprint)
{
	unsigned int	num;
	bool			is_zero;

	printf_int_adjust(conv);
	is_zero = false;
	num = va_arg(ap, unsigned int);
	if (num == 0)
		is_zero = true;
	if ((*conv).specifier == 'x')
		(*conv).string = ft_ullitoa_base(num, LOWER_HEX_BASE, false);
	else
		(*conv).string = ft_ullitoa_base(num, UPPER_HEX_BASE, false);
	if ((*conv).string)
	{
		(*conv).len = ft_strlen((*conv).string);
		printf_print(*conv, nprint, is_zero, false);
	}
	else
		*nprint = -1;
	ft_strdel(&(*conv).string);
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
	if ((*conv).string)
	{
		(*conv).len = ft_strlen((*conv).string);
		printf_print(*conv, nprint, false, false);
	}
	else
		*nprint = -1;
	ft_strdel(&(*conv).string);
}
