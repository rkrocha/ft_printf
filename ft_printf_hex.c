/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:50:43 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/12 15:48:56 by rkochhan         ###   ########.fr       */
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
	return (false);
}

void		printf_hex(t_params *conv, va_list ap, int *nprint)
{
	long	num;
	// int		num_len;
	// int		print_len;

	if (printf_hex_errors(conv, nprint))
		return ;
	if ((*conv).specifier == 'x' || (*conv).specifier == 'X')
		num = (long)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, long);
	ft_putlnbr_base(num, LOW_HEX_BASE, ft_strlen(LOW_HEX_BASE));
}
