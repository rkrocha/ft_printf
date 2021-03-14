/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:21:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 15:05:44 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_str(t_params *conv, va_list ap, int *nprint)
{
	char	*temp;
	size_t	len;

	// printf_str_errors?
	temp = va_arg(ap, char *);
	if ((*conv).precision < 0)
		(*conv).flag_precision = false;
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
	(*conv).precision = 0;
	len = ft_strlen((*conv).string);

	*nprint += 1;
	printf_print(*conv, len, false, false);
	ft_strdel(&(*conv).string);
}
