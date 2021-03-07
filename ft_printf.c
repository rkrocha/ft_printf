/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/07 19:11:25 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_conversion(const char *format, va_list arg, int *nprint, int *i)
{
	t_conversion	conv;

	(void)arg;
	ft_bzero(&conv, sizeof(conv));
	if (!copy_conv_spec(format, &conv, i))
	{
		*nprint = -1;
		return ;
	}
	get_flags(&conv);
	// get_bonus_flags?
	// get_width_precision(&conv);
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
