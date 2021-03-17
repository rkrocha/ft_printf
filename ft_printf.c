/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/16 23:33:34 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	branch_by_specifier(t_params *conv, va_list ap, int *nprint)
{
	if ((*conv).specifier == 'c')
		printf_char(conv, ap, nprint);
	else if ((*conv).specifier == 's')
		printf_prep_str(conv, ap, nprint);
	else if ((*conv).specifier == 'p')
		printf_prep_ptr(conv, ap, nprint);
	else if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		printf_prep_int(conv, ap, nprint);
	else if ((*conv).specifier == 'u')
		printf_prep_int(conv, ap, nprint);
	else if ((*conv).specifier == 'x' || (*conv).specifier == 'X')
		printf_prep_hex(conv, ap, nprint);
	else if ((*conv).specifier == '%')
		printf_percent(conv, nprint);
	return ;
}

static void	get_conversion(const char *format, va_list ap, int *nprint, int *i)
{
	t_params	conv;

	ft_bzero(&conv, sizeof(conv));
	if (printf_copy_conv(format, &conv, i))
	{
		printf_get_flags(&conv, ap); // duplicate flags?
		ft_strdel(&(conv.string));
		branch_by_specifier(&conv, ap, nprint);
		return ;
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
			get_conversion(format, ap, &nprint, &i);
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
