/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:48:09 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 13:59:07 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_put_ptr(t_params conv, size_t len, bool is_zero, bool sign)
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
		ft_putnstr(conv.string, len);
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

void		printf_ptr(t_params *conv, va_list ap, int *nprint)
{
	unsigned long	num;
	char			*temp;

	(void)nprint;
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
	printf_put_ptr(*conv, ft_strlen((*conv).string), false, false);
	ft_strdel(&(*conv).string);
}
