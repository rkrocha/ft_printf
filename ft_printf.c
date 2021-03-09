/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/09 09:01:44 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_by_specifier(t_params *conv, va_list ap, int *nprint)
{
	// if ((*conv).specifier == 'c' || (*conv).specifier == '%')
	// 	printf_char(conv, ap, nprint);
	// else if ((*conv).specifier == 's')
	// 	printf_str(conv, ap, nprint);
	// else if ((*conv).specifier == 'p')					// join with uint?
	// 	printf_ptr(conv, ap, nprint);
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		printf_int(conv, ap, nprint);
	// else if ((*conv).specifier == 'u')
	// 	printf_uint(conv, ap, nprint);
	// else if ((*conv).specifier == 'x' || (*conv).specifier == 'X')
	// 	printf_hex(conv, ap, nprint);
	return ;
}

static void	get_conversion(const char *format, va_list ap, int *nprint, int *i)
{
	t_params	conv;

	ft_bzero(&conv, sizeof(conv));
	if (copy_conversion(format, &conv, i))
	{
		get_flags(&conv);
		// get_bonus_flags?
		get_width_precision(&conv, ap);
		// get_bonus_length?
		// if (check_common_errors)?
			// break ;
		// else
		print_by_specifier(&conv, ap, nprint);
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
			ft_putchar(format[i]);				// optimize for fewer syscalls?
			nprint++;
			i++;
		}
	}
	va_end(ap);
	return (nprint);
}
