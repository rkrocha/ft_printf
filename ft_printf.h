/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:18:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/15 09:58:42 by rkochhan         ###   ########.fr       */
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
# define SUB_FORMAT_LEN 24

typedef struct	s_params
{
	char	sub_format[SUB_FORMAT_LEN];
	char	specifier;

	bool	flag_minus;
	bool	flag_zero;
	bool	flag_precision;
	bool	flag_star_width;
	bool	flag_star_preci;

	int		width;
	int		precision;

	char	*string;
	size_t	len;
}				t_params;

/*
** ft_printf.c:
*/
int				ft_printf(const char *format, ...);

/*
** ft_printf_conversion.c:
*/
bool			printf_copy_conv(const char *format, t_params *conv, int *i);
void			printf_get_flags(t_params *conv, char *sub_format);
void			printf_wid_preci(t_params *conv, va_list arg, char *sub_format);
bool			printf_errors(t_params *conv);

/*
** ft_printf_print_utils.c:
*/
void			printf_print(t_params conv, int *nprint, bool zero, bool sign);
void			printf_putchar(char c, int n, int *nprint);
void			printf_putstr(const char *str, int *nprint);

/*
** ft_printf_int_base.c:
*/
void			printf_int(t_params *conv, va_list arg, int *nprint);
void			printf_hex(t_params *conv, va_list ap, int *nprint);
void			printf_ptr(t_params *conv, va_list ap, int *nprint);

/*
** ft_printf_char_str.c:
*/
void			printf_char(t_params *conv, va_list ap, int *nprint);
void			printf_percent(t_params *conv, int *nprint);
void			printf_str(t_params *conv, va_list ap, int *nprint);

#endif
