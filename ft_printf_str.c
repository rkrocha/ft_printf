/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:21:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 15:13:03 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_str(t_params *conv, va_list ap, int *nprint)
{
	char	*temp;

	if ((*conv).precision < 0)
		(*conv).flag_precision = false; // printf errors?
	temp = va_arg(ap, char *);
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
	printf_print(*conv, ft_strlen((*conv).string), false, false);
	ft_strdel(&(*conv).string);
	*nprint +=1; // FIX
}
