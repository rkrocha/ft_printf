/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:18:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 14:27:25 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

# define PRINTF_SPECS "cspdiuxX%"
# define PRINTF_VALID "-0.*123456789"
# define PRINTF_FLAGS "-0.*"

typedef struct	s_params
{
	char	*sub_format;
	char	specifier;

	bool	flag_minus;
	bool	flag_zero;
	bool	flag_precision;
	bool	flag_star_width;
	bool	flag_star_preci;

	int		width;
	int		precision;

	char	*string;
}				t_params;

/*
** ft_printf.c:
*/
int				ft_printf(const char *format, ...);

/*
** ft_printf_utils.c:
*/
bool			copy_conversion(const char *format, t_params *conv, int *i);
void			get_flags(t_params *conv, char *sub_format);
void			get_width_preci(t_params *conv, va_list arg, char *sub_format);
bool			printf_errors(t_params *conv);
void			printf_pad(char c, int len);

void			printf_print(t_params conv, size_t len, bool is_zero, bool sign);

/*
** ft_printf_int.c:
*/
void			printf_int(t_params *conv, va_list arg, int *nprint);

/*
** ft_printf_char_percent.c:
*/
void			printf_char(t_params *conv, va_list ap, int *nprint);
void			printf_percent(t_params *conv, int *nprint);

/*
** ft_printf_str.c:
*/
void			printf_str(t_params *conv, va_list ap, int *nprint);

/*
** ft_printf_hex.c:
*/
void			printf_hex(t_params *conv, va_list ap, int *nprint);

/*
** ft_printf_ptr.c:
*/
void			printf_ptr(t_params *conv, va_list ap, int *nprint);

#endif
