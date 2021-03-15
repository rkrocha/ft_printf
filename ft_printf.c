/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 09:38:06 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_by_specifier(t_params *conv, va_list ap, int *nprint)
{
	if ((*conv).specifier == 'c')
		printf_char(conv, ap, nprint);
	else if ((*conv).specifier == 's')
		printf_str(conv, ap, nprint);
	else if ((*conv).specifier == 'p')
		printf_ptr(conv, ap, nprint);
	else if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		printf_int(conv, ap, nprint);
	else if ((*conv).specifier == 'u')
		printf_int(conv, ap, nprint);
	else if ((*conv).specifier == 'x' || (*conv).specifier == 'X')
		printf_hex(conv, ap, nprint);
	else if ((*conv).specifier == '%')
		printf_percent(conv, nprint);
	return ;
}

static void	print_conv(const char *format, va_list ap, int *nprint, int *i)
{
	t_params	conv;

	ft_bzero(&conv, sizeof(conv));
	if (printf_copy_conv(format, &conv, i))
	{
		printf_get_flags(&conv, conv.sub_format);
		// get_bonus_flags?
		printf_wid_preci(&conv, ap, conv.sub_format);
		// get_bonus_length?
		if (!printf_errors(&conv))//? negative wid and prec, multiple '.' or '*'
		{
			print_by_specifier(&conv, ap, nprint);
			return ;
		}
	}
	*nprint = -1;
	return ;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nprint;
	int		i;

	va_start(ap, format);
	nprint = 0;
	i = 0;
	while (format[i] != '\0' && nprint != -1)
	{
		if (format[i] == '%')
		{
			i++;
			print_conv(format, ap, &nprint, &i);
		}
		else
		{
			ft_putchar(format[i]);		// optimize for fewer syscalls?
			nprint++;
			i++;
		}
	}
	va_end(ap);
	return (nprint); // TEST RETURNS
}
