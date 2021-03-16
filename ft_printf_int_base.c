/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:53:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/16 10:10:03 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_int_adjust(t_params *conv)
{
	if ((*conv).flag_minus && (*conv).flag_zero)
		(*conv).flag_zero = false;
	if ((*conv).flag_zero && (*conv).flag_precision && (*conv).precision >= 0)
		(*conv).flag_zero = false;
	if ((*conv).precision < 0)
	{
		(*conv).flag_precision = false;
		(*conv).precision = 0;
	}
}

void		printf_prep_int(t_params *conv, va_list ap, int *nprint)
{
	long	num;
	bool	sign;
	bool	is_zero;

	printf_int_adjust(conv);
	is_zero = false;
	sign = false;
	if ((*conv).specifier == 'd' || (*conv).specifier == 'i')
		num = (long)va_arg(ap, int);
	else
		num = (long)va_arg(ap, unsigned int);
	if (num < 0)
	{
		num *= -1;
		sign = true;
	}
	if (num == 0)
		is_zero = true;
	(*conv).string = ft_ullitoa_base(num, DECIMAL_BASE, false);
	if ((*conv).string && ((*conv).len = ft_strlen((*conv).string) + sign))
		printf_print(*conv, nprint, is_zero, sign);
	else
		*nprint = -1;
	ft_strdel(&(*conv).string);
}

void		printf_prep_hex(t_params *conv, va_list ap, int *nprint)
{
	unsigned int	num;
	bool			is_zero;

	printf_int_adjust(conv);
	is_zero = false;
	num = va_arg(ap, unsigned int);
	if (num == 0)
		is_zero = true;
	if ((*conv).specifier == 'x')
		(*conv).string = ft_ullitoa_base(num, LOWER_HEX_BASE, false);
	else
		(*conv).string = ft_ullitoa_base(num, UPPER_HEX_BASE, false);
	if ((*conv).string)
	{
		(*conv).len = ft_strlen((*conv).string);
		printf_print(*conv, nprint, is_zero, false);
	}
	else
		*nprint = -1;
	ft_strdel(&(*conv).string);
}

static char	*ptr_pad(t_params conv, char *temp)
{
	char	*str;
	int		len;
	int		pad;

	if (!temp)
		return (NULL);
	len = ft_strlen(temp);
	if (conv.flag_precision && conv.precision > (len + 2))
		pad = conv.precision - len + 2;
	else if (conv.flag_zero && conv.width > (len + 2))
		pad = conv.width - len;
	else
		pad = 2;
	if (!(str = (char *)malloc((pad + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '0', pad);
	str[1] = 'x';
	str[pad] = '\0';
	return (str);
}

void		printf_prep_ptr(t_params *conv, va_list ap, int *nprint)
{
	unsigned long	num;
	char			*pad;
	char			*temp;

	printf_int_adjust(conv);
	num = va_arg(ap, unsigned long);
	pad = NULL;
	if (num == 0 && (*conv).flag_precision && (*conv).precision == 0)
		(*conv).string = ft_strdup("0x");
	else
	{
		temp = ft_ullitoa_base(num, LOWER_HEX_BASE, false);
		pad = ptr_pad(*conv, temp);
		(*conv).string = ft_strjoin(pad, temp);
		ft_strdel(&temp);
	}
	if ((*conv).string)
	{
		(*conv).len = ft_strlen((*conv).string);
		printf_print(*conv, nprint, false, false);
	}
	else
		*nprint = -1;
	ft_strdel(&pad);
	ft_strdel(&(*conv).string);
}
