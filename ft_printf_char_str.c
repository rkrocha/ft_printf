/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:44 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 08:33:01 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Always prints a '%', using width but ignoring precision.
**	The '0' flag is ignored when '-' flag is present.
*/
void	printf_percent(t_params *conv, int *nprint)
{
	// print_percent_errors?
	if ((*conv).flag_minus && (*conv).flag_zero) // move to common_errors?
		(*conv).flag_zero = false;
	if ((*conv).width > 1)
		*nprint += (*conv).width;	// check ft_printf return
	else
		*nprint += 1;
	if (!(*conv).flag_minus && !(*conv).flag_zero && (*conv).width > 1)
		printf_pad(' ', (*conv).width - 1);
	else if ((*conv).flag_zero && (*conv).width > 1)
		printf_pad('0', (*conv).width - 1);
	ft_putchar('%');
	if ((*conv).flag_minus && (*conv).width > 1)
		printf_pad(' ', (*conv).width - 1);
}

// REVIEW BOTH FUNCTIONS. CAN PRINTF_CHAR PRINT PERCENT?

/*
** Precision and '0' flags result in undefined behavior with c conversion.
** The '0' flag is ignored when '-' flag is present.
*/
void	printf_char(t_params *conv, va_list ap, int *nprint)
{
	unsigned char	c;

	// printf_char_errors?
	c = (unsigned char)va_arg(ap, int); // treat as int to suppress error?
	if (!(*conv).flag_minus && (*conv).width > 1)
		printf_pad(' ', (*conv).width - 1);
	ft_putchar(c);
	if ((*conv).flag_minus && (*conv).width > 1)
		printf_pad(' ', (*conv).width - 1);
	*nprint += 1;
}

void	printf_str(t_params *conv, va_list ap, int *nprint)
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
