/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/08 11:49:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width_precision(t_params *conv, va_list arg)
{
	char	*ptr;
	int		j;

	j = 0;
	while (!(*conv).width && !(*conv).flag_star_width && (*conv).string[j])
	{
		if (ft_isdigit((*conv).string[j]) && (*conv).string[j] != '0')
		{
			if ((void *)&((*conv).string[j]) == (void *)conv)	// unfuck this
				(*conv).width = ft_atoi(&(*conv).string[j]);	// fucking mess
			else if ((void *)&((*conv).string[j]) > (void *)conv &&
												(*conv).string[j - 1] != '.')
				(*conv).width = ft_atoi(&(*conv).string[j]);
		}
		j++;
	}
	if ((*conv).flag_precision && !(*conv).flag_star_preci)
		if ((ptr = ft_strchr((*conv).string, '.')))
			(*conv).precision = ft_atoi(ptr + 1);
	if ((*conv).flag_star_width)
		(*conv).width = va_arg(arg, int);
	if ((*conv).flag_star_preci)
		(*conv).precision = va_arg(arg, int);
	ptr = NULL;
}

void	get_flags(t_params *conv)
{
	char	*ptr;
	int		j;

	j = 0;
	if (ft_strchr((*conv).string, '-'))
		(*conv).flag_minus = true;
	while ((*conv).string[j] && ft_strchr(PRINTF_FLAGS, (*conv).string[j]))
	{
		if ((*conv).string[j++] == '0')
			(*conv).flag_zero = true;
	}
	if (ft_strchr((*conv).string, '.'))
		(*conv).flag_precision = true;
	if ((ptr = (ft_strrchr((*conv).string, '*'))))
	{
		if ((void *)ptr > (void *)conv && *(ptr - 1) == '.')
			(*conv).flag_star_preci = true;
		else
			(*conv).flag_star_width = true;
	}
	if ((ptr != (ft_strchr((*conv).string, '*'))))
		(*conv).flag_star_width = true;
	ptr = NULL;
}

bool	copy_conversion(const char *format, t_params *conv, int *i)
{
	int	j;

	j = 0;
	while (j < 23 && format[*i] && ft_strchr(PRINTF_CONVERSION, format[*i]))
	{
		(*conv).string[j] = format[*i];
		(*i)++;
		j++;
		if (ft_strchr(PRINTF_SPECS, (*conv).string[j - 1]))
		{
			(*conv).specifier = (*conv).string[j - 1];
			return (true);
		}
	}
	return (false);
}
