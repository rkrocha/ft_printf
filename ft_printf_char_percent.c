/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:44 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/12 15:56:18 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Always prints a '%', using width but ignoring precision.
** '-' flag makes function to implicitly ignore '0' flag, but each is valid.
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
** Precision and '0' flags result in undefined behavior with c conversion
** '0' flag is ignored when '-' flag is present.
*/
void	printf_char(t_params *conv, va_list ap, int *nprint)
{
	unsigned char	c;

	// printf_char_errors?
	c = (unsigned char)va_arg(ap, int); // treat as int to suppress error?
	if ((*conv).width > 1)
		*nprint += (*conv).width;	// check ft_printf return
	else
		*nprint += 1;
	if (!(*conv).flag_minus && (*conv).width > 1)
		printf_pad(' ', (*conv).width - 1);
	ft_putchar(c);
	if ((*conv).flag_minus && (*conv).width > 1)
		printf_pad(' ', (*conv).width - 1);
}
