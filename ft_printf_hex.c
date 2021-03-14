/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:50:43 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 16:16:31 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	printf_hex_errors(t_params *conv, int *nprint)
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

void		printf_hex(t_params *conv, va_list ap, int *nprint)
{
	unsigned int	num;
	bool			is_zero;

	is_zero = false;
	if (printf_hex_errors(conv, nprint))
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
