/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:21:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/11 04:38:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_put_str(t_params *conv, char *str, size_t len)
{
	if (!(*conv).flag_minus)
	{
		if ((*conv).precision > 0 && (size_t)(*conv).precision < len)
			printf_pad(' ', (*conv).width - (*conv).precision);
		else if ((size_t)(*conv).width > len)
			printf_pad(' ', (*conv).width - len);
	}
	if ((*conv).flag_precision)
		ft_putnstr(str, (*conv).precision);
	else
		ft_putstr(str);
	if ((*conv).flag_minus && (size_t)(*conv).width > len)
		printf_pad(' ', (*conv).width - len);
}

void		printf_str(t_params *conv, va_list ap, int *nprint)
{
	char	*str;
	size_t	len;
	size_t	print_len;

	// printf_str_errors?
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if ((*conv).flag_precision && (size_t)(*conv).precision < len)
		print_len = (*conv).precision;
	if ((size_t)(*conv).width > print_len)
		print_len = (*conv).width;
	*nprint += print_len;				// check ft_printf return
	if (print_len == len && (size_t)(*conv).precision >= len)
		ft_putstr(str);
	else
		printf_put_str(conv, str, len);
}
