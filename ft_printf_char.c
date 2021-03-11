/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:44 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/11 16:58:17 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Precision and '0' flags result in undefined behavior with c conversion
** '0' flag is ignored when '-' flag is present.
*/

void		printf_char(t_params *conv, va_list ap, int *nprint)
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
		*nprint += (*conv).width;
		if (!(*conv).flag_minus && (*conv).width > 1)
			printf_pad(' ', (*conv).width - 1);
		ft_putchar(c);
		if ((*conv).flag_minus && (*conv).width > 1)
			printf_pad(' ', (*conv).width - 1);
	}
}
