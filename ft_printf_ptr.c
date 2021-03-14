/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:48:09 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 14:26:59 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_ptr(t_params *conv, va_list ap, int *nprint)
{
	unsigned long	num;
	char			*temp;

	(void)nprint;
	if ((*conv).flag_zero && (*conv).precision > 0) // common errors?
		(*conv).flag_zero = false;

	num = va_arg(ap, unsigned long);
	if (num == 0 && (*conv).flag_precision && (*conv).precision == 0)
		(*conv).string = ft_strdup("0x");
	else
	{
		temp = ft_ullitoa_base(num, LOWER_HEX_BASE, false);
		(*conv).string = ft_strjoin("0x", temp);
		ft_strdel(&temp);
	}
	printf_print(*conv, ft_strlen((*conv).string), false, false);
	ft_strdel(&(*conv).string);
}
