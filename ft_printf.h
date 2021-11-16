/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:18:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/11/16 08:12:50 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define PRINTF_SPECIFIERS	"cspdiuxX%"
# define PRINTF_CONV_CHARS	"-0.*123456789"
# define PRINTF_FLAGS		"-0.*"

typedef struct s_params
{
	char	*string;
	char	specifier;
	t_bool	flag_minus;
	t_bool	flag_zero;
	t_bool	flag_precision;
	int		precision;
	int		width;
	int		len;
}				t_params;

/*
** ft_printf.c:
*/
int		ft_printf(const char *format, ...);

/*
** ft_printf_conversion.c:
*/
t_bool	printf_copy_conv(char **start, t_params *conv);
void	printf_get_flags(t_params *conv, va_list ap);

/*
** ft_printf_char_str.c:
*/
void	printf_char(t_params conv, va_list ap, int *nprint);
void	printf_prep_str(t_params *conv, va_list ap, int *nprint);

/*
** ft_printf_int_base.c:
*/
void	printf_prep_int(t_params *conv, va_list ap, int *nprint);
void	printf_prep_hex(t_params *conv, va_list ap, int *nprint);
void	printf_prep_ptr(t_params *conv, va_list ap, int *nprint);

/*
** ft_printf_print_utils.c:
*/
void	printf_print(t_params conv, int *nprint, t_bool zero, t_bool sign);
void	printf_putchar(char c, int n, int *nprint);
void	printf_putstr(const char *str, int *nprint);

#endif
