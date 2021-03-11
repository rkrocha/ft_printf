/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:44 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/11 03:05:49 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_put_char(t_params *conv, unsigned char c, int *nprint)
{
	(void)conv;
	(void)nprint;
	ft_putchar(c);
}

void	printf_char(t_params *conv, va_list ap, int *nprint)
{
	unsigned char	c;

	// printf_char_errors?
	if ((*conv).specifier == '%')
	{
		c = '\0';
		*nprint += 1;
		ft_putchar('%');
	}
	if ((*conv).specifier == 'c')
	{
		c = (unsigned char)va_arg(ap, int); // treat as int to suppress error?
		printf_put_char(conv, c, nprint);
	}
}
