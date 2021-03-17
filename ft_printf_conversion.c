/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/16 23:33:44 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_precision_value(t_params *conv, va_list ap, char *tracker)
{
	if (ft_isdigit(*tracker))
	{
		(*conv).precision = ft_atoi(tracker);
		tracker = ft_strignore(tracker, "0123456789");
		tracker = ft_strsearch(tracker, ".123456789*");
	}
	else if (*tracker == '*')
	{
		(*conv).precision = va_arg(ap, int);
		tracker++;
		tracker = ft_strsearch(tracker, ".123456789*");
	}
	else
		(*conv).precision = 0;
	if ((*conv).precision < 0)
	{
		(*conv).flag_precision = false;
		(*conv).precision = 0;
	}
	return (tracker);
}

static void	get_width_precision(t_params *conv, va_list ap)
{
	char	*tracker;

	tracker = ft_strsearch((*conv).string, ".123456789*");
	while (tracker && *tracker)
	{
		if (*tracker == '.')
			tracker = get_precision_value(conv, ap, tracker + 1);
		else if (ft_isdigit(*tracker))
		{
			(*conv).width = ft_atoi(tracker);
			tracker = ft_strignore(tracker, "0123456789");
			tracker = ft_strsearch(tracker, ".123456789*");
		}
		else if (*tracker == '*')
		{
			(*conv).width = va_arg(ap, int);
			tracker++;
			tracker = ft_strsearch(tracker, ".123456789*");
		}
		else
			break ;
	}
}

void		printf_get_flags(t_params *conv, va_list ap)
{
	char	*ptr;
	char	*sub_format;

	sub_format = (*conv).string;
	if (ft_strchr(sub_format, '.'))
		(*conv).flag_precision = true;
	if (ft_strchr(sub_format, '-'))
		(*conv).flag_minus = true;
	ptr = ft_strchr(sub_format, '0');
	while (ptr)
	{
		if (ptr == sub_format || (*(ptr - 1) != '.' && !ft_isdigit(*(ptr - 1))))
			(*conv).flag_zero = true;
		ptr++;
		ptr = ft_strchr(ptr, '0');
	}
	get_width_precision(conv, ap);
		if ((*conv).width < 0)
	{
		(*conv).width *= -1;
		(*conv).flag_minus = true;
	}
}

bool		printf_copy_conv(const char *format, t_params *conv, int *i)
{
	const char	*start;
	const char	*end;

	start = &format[*i];
	if ((end = ft_strsearch(start, PRINTF_SPECS)))
	{
		if (end - start + 1 < SUB_FORMAT_LEN) // keep format len?
		{
			if (end == ft_strignore(start, PRINTF_VALID))
			{
				(*conv).string = ft_substr(start, 0, end - start + 1);
				(*conv).specifier = *end;
				*i += end - start + 1;
				if ((*conv).string)
					return (true);
			}
		}
	}
	return (false);
}
