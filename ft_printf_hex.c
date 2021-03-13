/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:50:43 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/13 11:25:25 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_put_hex(t_params conv, unsigned int num, int num_len, char *base)
{
	if (!conv.flag_minus)
	{
		if (conv.precision >= num_len)
			printf_pad(' ', conv.width - conv.precision);
		else if (!conv.flag_zero)
			printf_pad(' ', conv.width - num_len);
	}
	if (conv.precision >= num_len)
		printf_pad('0', conv.precision - num_len);
	else if (conv.flag_zero && conv.width > num_len)
		printf_pad('0', conv.width - num_len);
	if (!(num == 0 && conv.flag_precision && conv.precision == 0))
		ft_putlnbr_base(num, base, ft_strlen(base));
	else if (num == 0 && conv.width > 0)
		ft_putchar(' ');
	if (conv.flag_minus)
	{
		if (conv.width > num_len && conv.precision > num_len)
			printf_pad(' ', conv.width - conv.precision);
		else if (conv.width > num_len)
			printf_pad(' ', conv.width - num_len);
	}
}

static int	count_hex_digits(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

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
	unsigned int	num;
	int				num_len;
	int				print_len;

	if (printf_hex_errors(conv, nprint))
		return ;
	num = va_arg(ap, unsigned int);
	num_len = count_hex_digits(num);
	print_len = num_len;
	if ((*conv).width > num_len)
		print_len = (*conv).width;
	if ((*conv).precision > num_len)
		print_len = (*conv).precision;
	*nprint += print_len;
	if ((*conv).specifier == 'x')
		printf_put_hex(*conv, num, num_len, LOWER_HEX_BASE);
	else
		printf_put_hex(*conv, num, num_len, UPPER_HEX_BASE);
}
