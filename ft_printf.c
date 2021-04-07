/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 14:17:48 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	branch_by_specifier(t_params *conv, va_list ap, int *nprint)
{
	if ((*conv).specifier == 'c')
		printf_char(*conv, ap, nprint);
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
		printf_char(*conv, ap, nprint);
	return ;
}

static void	get_conversion(char **sub_format, int *nprint, va_list ap)
{
	t_params	conv;

	ft_bzero(&conv, sizeof(conv));
	if (printf_copy_conv(sub_format, &conv))
	{
		printf_get_flags(&conv, ap);
		ft_strdel(&(conv.string));
		branch_by_specifier(&conv, ap, nprint);
		return ;
	}
	*nprint = -1;
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*sub_format;
	char	*printed;
	int		nprint;

	va_start(ap, format);
	nprint = 0;
	printed = (char *)format;
	while (nprint != -1)
	{
		sub_format = ft_strchr(printed, '%');
		if (!sub_format)
			break ;
		ft_putnstr(printed, sub_format - printed);
		nprint += sub_format - printed;
		get_conversion(&sub_format, &nprint, ap);
		printed = sub_format;
	}
	if (nprint != -1 && printed && *printed)
	{
		ft_putstr(printed);
		nprint += ft_strlen(printed);
	}
	va_end(ap);
	return (nprint);
}
