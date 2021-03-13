/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:53:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/13 08:13:49 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**		From what I could gather, the most reasonable way to print this
**	conversion in one go without allocating a string was to do so in the
**	following order:
**
**	1. If there's no '-' flag, then pad with spaces according to given
**		precision or width. A sign (such as a negative sign) counts as
**		width but not as precision.
**
**	2. If the number to be printed is negative (or has any sign, or
**		space padding in case of ' ' flag), then print the sign.
**
**	3. If the specified precision value is larger or equal to the amount
**		of int digits to print, or if the '0' flag is in play and width
**		is larger or equal to the amount of int digits to print, then
**		pad with zeroes.
**
**	4. WORK IN PROGRESS
**
**	5. If the conversion printed so far was left-justified ('-' flag),
**		then there may be space padding to print depending on width,
**		precision, and the amount of digits to print.
**
**	This is the logic used in the function prinft_put_int seen below.
*/

static void	printf_put_int(t_params conv, long num, int num_len, bool num_neg)
{
	if (!conv.flag_minus)
	{
		if (conv.precision >= num_len)
			printf_pad(' ', conv.width - conv.precision - num_neg);
		else if (!conv.flag_zero)
			printf_pad(' ', conv.width - num_len);
	}
	if (num_neg)
		ft_putchar('-');
	if (conv.precision >= num_len)
		printf_pad('0', conv.precision - num_len + num_neg);
	else if (conv.flag_zero && conv.width > num_len)
		printf_pad('0', conv.width - num_len);
	if (!(num == 0 && conv.flag_precision && conv.precision == 0))
		ft_putlnbr(num);
	else if (num == 0 && conv.width > 0)
		ft_putchar(' ');
	if (conv.flag_minus)
	{
		if (conv.width > num_len && conv.precision > num_len)
			printf_pad(' ', conv.width - conv.precision - num_neg);
		else if (conv.width > num_len)
			printf_pad(' ', conv.width - num_len);
	}
}

static int	printf_int_len(t_params conv, int len)
{
	if (conv.width > len)
		len = conv.width;
	if (conv.precision > len)
		len = conv.precision;
	return (len);
}

static bool	printf_int_errors(t_params *conv, int *nprint)
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

void		printf_int(t_params *conv, va_list ap, int *nprint)
{
	long	num;
	int		num_len;
	bool	num_neg;
	int		print_len;

	if (printf_int_errors(conv, nprint))
		return ;
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		num = (long)va_arg(ap, int);
	else
		num = (long)va_arg(ap, unsigned int);
	num_len = ft_count_digits(num);
	print_len = printf_int_len(*conv, num_len);	// check ft_printf return
	*nprint += print_len;
	num_neg = false;
	if (num < 0)
	{
		num *= -1;
		num_neg = true;
	}
	printf_put_int(*conv, num, num_len, num_neg);
}
