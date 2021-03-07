/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/07 19:11:23 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	get_width_precision(t_conversion *conv)
// {
// 	int		j;

// 	j = 0;

// }

void	get_flags(t_conversion *conv)
{
	char	*ptr;
	int		j;

	j = 0;
	if (ft_strchr((*conv).conversion, '-'))
		(*conv).flag_minus = true;
	while ((*conv).conversion[j] &&
								ft_strchr(PRINTF_FLAGS, (*conv).conversion[j]))
	{
		if ((*conv).conversion[j++] == '0')
			(*conv).flag_zero = true;
	}
	if ((ptr = ft_strchr((*conv).conversion, '.')))
		(*conv).flag_precision = true;
	if ((ptr = (ft_strrchr((*conv).conversion, '*'))))
	{
		if ((void *)ptr > (void *)conv && *(ptr - 1) == '.')
			(*conv).flag_star_preci = true;
		else
			(*conv).flag_star_width = true;
	}
	if ((ptr != (ft_strchr((*conv).conversion, '*'))))
		(*conv).flag_star_width = true;
	ptr = NULL;
}

bool	copy_conv_spec(const char *format, t_conversion *conv, int *i)
{
	int	j;

	j = 0;
	while (j < 23 && format[*i] && ft_strchr(PRINTF_CONVERSION, format[*i]))
	{
		(*conv).conversion[j] = format[*i];
		(*i)++;
		j++;
		if (ft_strchr(PRINTF_SPECS, (*conv).conversion[j - 1]))
		{
			(*conv).specifier = (*conv).conversion[j - 1];
			return (true);
		}
	}
	return (false);
}
