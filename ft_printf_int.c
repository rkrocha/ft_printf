/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:53:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/10 11:07:31 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_printf_int(t_params *conv, long num, int num_len, bool num_neg)
{
	if (!(*conv).flag_minus)
	{
		if ((*conv).precision >= num_len)
			printf_pad(' ', (*conv).width - (*conv).precision - num_neg);
		else if (!(*conv).flag_zero)
			printf_pad(' ', (*conv).width - num_len);
	}
	if (num_neg)
		ft_putchar('-');
	if ((*conv).precision >= num_len)
		printf_pad('0', (*conv).precision - num_len + num_neg);
	else if ((*conv).flag_zero && (*conv).width > num_len)
		printf_pad('0', (*conv).width - num_len);
	if (num > 0 || (*conv).precision > 0 || (*conv).flag_zero)
		ft_putlnbr(num);
	else if (num == 0 && (*conv).width > 0)
		ft_putchar(' ');
	if ((*conv).flag_minus)
	{
		if ((*conv).width > num_len && (*conv).precision > num_len)
			printf_pad(' ', (*conv).width - (*conv).precision - num_neg);
		else if ((*conv).width > num_len)
			printf_pad(' ', (*conv).width - num_len);
	}
}
// if (num > 0 || (num >= 0 && (*conv).precision > 0))

static int	printf_int_len(t_params *conv, int num_len)
{
	if ((*conv).width > num_len)
		num_len = (*conv).width;
	if ((*conv).precision > num_len)
		num_len = (*conv).precision;
	return (num_len);
}

static bool	printf_int_errors(t_params *conv, int *nprint)
{
	if ((*conv).flag_minus && (*conv).flag_zero)
	{
		*nprint = -1;
		return (true);
	}
	if ((*conv).flag_zero && (*conv).precision > 0)
		(*conv).flag_zero = false;
	return (false);
}

void		printf_int(t_params *conv, va_list ap, int *nprint)
{
	long	num;
	int		num_len;
	int		print_len;
	bool	num_neg;

	if (printf_int_errors(conv, nprint))
		return ;
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		num = (long)va_arg(ap, int);
	else
		num = (long)va_arg(ap, unsigned int);
	num_len = ft_lintlen(num);
	print_len = printf_int_len(conv, num_len);
	*nprint += print_len;							// check ft_printf return
	num_neg = false;
	if (num < 0)
	{
		num *= -1;
		num_neg = true;
	}
	if (print_len == num_len && !num_neg)
		ft_putlnbr(num);
	else
		put_printf_int(conv, num, num_len, num_neg);
}
