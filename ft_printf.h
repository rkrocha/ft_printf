/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:18:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/06 23:54:45 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include "./libft/libft.h"

# define PRINTF_FLAGS "-0.*"
# define PRINTF_SPECS "cspdiuxX%"
# define PRINTF_CONVERSION "-0.*cspdiuxX%123456789"

typedef struct	s_conversion
{
	char	conversion[24];
	char	specifier;

	bool	flag_minus;
	bool	flag_zero;
	bool	flag_precision;
	bool	flag_star_width;
	bool	flag_star_preci;

	int		width;
	int		precision;
}				t_conversion;

int				ft_printf(const char *format, ...);
bool			copy_conv_spec(const char *format, t_conversion *conv, int *i);
void			get_flags(t_conversion *conv);

#endif
