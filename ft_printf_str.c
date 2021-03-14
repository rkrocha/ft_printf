/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:21:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 14:57:09 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void	printf_put_str(t_params conv, char *str, size_t len)
// {
// 	if (!conv.flag_minus)
// 	{
// 		if (conv.flag_precision && conv.width > conv.precision &&
// 												(size_t)conv.precision < len)
// 			printf_pad(' ', conv.width - conv.precision);
// 		else if ((size_t)conv.width > len)
// 			printf_pad(' ', conv.width - len);
// 	}
// 	if (conv.flag_precision)
// 		ft_putnstr(str, conv.precision);
// 	else
// 		ft_putstr(str);
// 	if (conv.flag_minus)
// 	{
// 		if (conv.flag_precision && (size_t)conv.precision < len)
// 			printf_pad(' ', conv.width - conv.precision);
// 		else if ((size_t)conv.width > len)
// 			printf_pad(' ', conv.width - len);
// 	}
// }

void		printf_str(t_params *conv, va_list ap, int *nprint)
{
	char	*temp;
	size_t	len;

	// printf_str_errors?
	temp = va_arg(ap, char *);
	if ((*conv).precision < 0)
		(*conv).precision *= -1;
	if (temp == NULL)
	{
		if ((*conv).flag_precision)
			(*conv).string = ft_substr("(null)", 0 , (*conv).precision);
		else
			(*conv).string = ft_strdup("(null)");
	}
	else
	{
		if ((*conv).flag_precision)
			(*conv).string = ft_substr(temp, 0, (*conv).precision);
		else
			(*conv).string = ft_strdup(temp);
	}
	len = ft_strlen((*conv).string);
	(*conv).precision = 0;

	*nprint += 1;
	printf_print(*conv, len, false, false);
	ft_strdel(&(*conv).string);
}
