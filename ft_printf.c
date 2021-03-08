/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/08 12:04:04 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	branch_by_specifier(t_params *conv, va_list arg, int *nprint)
{
	// if ((*conv).specifier == 'c' || (*conv).specifier == '%')
	// 	printf_char(conv, arg, nprint);
	// else if ((*conv).specifier == 's')
	// 	printf_str(conv, arg, nprint);
	// else if ((*conv).specifier == 'p')
	// 	printf_ptr(conv, arg, nprint);
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		printf_int(conv, arg, nprint);
	// else if ((*conv).specifier == 'u')
	// 	printf_uint(conv, arg, nprint);
	// else if ((*conv).specifier == 'x' || (*conv).specifier == 'X')
	// 	printf_hex(conv, arg, nprint);
	return ;
}

static void	get_conversion(const char *format, va_list arg, int *nprint, int *i)
{
	t_params	conv;

	ft_bzero(&conv, sizeof(conv));
	if (copy_conversion(format, &conv, i))
	{
		get_flags(&conv);
		// get_bonus_flags?
		get_width_precision(&conv, arg);
		// get_bonus_length?
		// if (check_common_errors)?
			// break ;
		// else
		branch_by_specifier(&conv, arg, nprint);
		return ;
	}
	*nprint = -1;
	return ;
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	int		nprint;
	int		i;

	va_start(arg, format);
	nprint = 0;
	i = 0;
	while (format[i] != '\0' && nprint != -1)
	{
		if (format[i] == '%')
		{
			i++;
			get_conversion(format, arg, &nprint, &i);
		}
		else
		{
			ft_putchar(format[i]);
			nprint++;
			i++;
		}
	}
	va_end(arg);
	return (nprint);
}
