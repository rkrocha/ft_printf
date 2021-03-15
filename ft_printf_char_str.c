/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:44 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 09:45:30 by rkochhan         ###   ########.fr       */
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
	if (!(*conv).flag_minus && !(*conv).flag_zero && (*conv).width > 1)
		printf_putchar(' ', (*conv).width - 1, nprint);
	else if ((*conv).flag_zero && (*conv).width > 1)
		printf_putchar('0', (*conv).width - 1, nprint);
	printf_putchar('%', 1, nprint);
	if ((*conv).flag_minus && (*conv).width > 1)
		printf_putchar(' ', (*conv).width - 1, nprint);
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
		printf_putchar(' ', (*conv).width - 1, nprint);
	printf_putchar(c, 1, nprint);
	if ((*conv).flag_minus && (*conv).width > 1)
		printf_putchar(' ', (*conv).width - 1, nprint);
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
	if ((*conv).string)
	{
		(*conv).len = ft_strlen((*conv).string);
		printf_print(*conv, nprint, false, false);
	}
	else
		*nprint = -1;
	ft_strdel(&(*conv).string);
}