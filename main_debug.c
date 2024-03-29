/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:35:21 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/23 08:58:13 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%10.5d   %10s\n", 300, "HELLO");
	ft_printf("%10.5d   %10s\n\n", 300, "HELLO");

	printf("%10.5u %8p\n", -1024u, NULL);
	ft_printf("%10.5u %8p\n\n", -1024u, NULL);

	// printf("");
	ft_printf("");

	printf("aaa\n");
	ft_printf("aaa\n");
}
