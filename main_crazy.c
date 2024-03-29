/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:04:03 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/17 15:17:15 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 973 IS THE MAGIC NUMBER!

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("printf empty format:\n|");
	printf("");
	printf("|\nft_printf empty format:\n|");
	ft_printf("");
	printf("|\n\n");

	printf("printf empty format with args:\n|");
	printf("", 1, 2, 3);
	printf("|\nft_printf empty format with args:\n|");
	ft_printf("", 1, 2, 3);
	printf("|\n\n");

	printf("printf conversion without args:\n|");
	printf("%c");
	printf("|\nft_printf conversion without args:\n|");
	ft_printf("%c");
	printf("|\n\n");

	printf("l-->|%10**9.**7.5**.10**2.**.*d|<--\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);
	ft_printf("l-->|%10**9.**7.5**.10**2.**.*d|<--\n\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);

	printf("\n_____INTS_____\n");
	printf("a-->|%10*9.*7.5d|<--\n", 8, 11, 13, 42);
	ft_printf("a-->|%10*9.*7.5d|<--\n\n", 8, 11, 13, 42);

	printf("b-->|%10*9*5d|<--\n", 8, 11, 13, 42);
	ft_printf("b-->|%10*9*5d|<--\n\n", 8, 11, 13, 42);

	printf("c-->|%10*9*.*7d|<--\n", 4, 6, 3, 42);
	ft_printf("c-->|%10*9*.*7d|<--\n\n", 4, 6, 3, 42);

	printf("x-->|%*10*12d|<--\n", 6, 3, 0, 42);
	ft_printf("x-->|%*10*12d|<--\n\n", 6, 3, 0, 42);

	printf("y-->|%.10*d|<--\n", 6, 3, 0, 42);
	ft_printf("y-->|%.10*d|<--\n\n", 6, 3, 0, 42);

	printf("z-->|%.10*12*d|<--\n", 6, 3, 0, 42);
	ft_printf("z-->|%.10*12*d|<--\n\n", 6, 3, 0, 42);

	printf("0-->|%6..5*d|<--\n", 6, 3, 0, 42);
	ft_printf("0-->|%6..5*d|<--\n\n", 6, 3, 0, 42);

	printf("1-->|%----16..d|<--\n", 6, 3, 0, 42);
	ft_printf("1-->|%----16..d|<--\n\n", 6, 3, 0, 42);

	printf("2-->|%0000d|<--\n", 6, 3, 0, 42);
	ft_printf("2-->|%0000d|<--\n\n", 6, 3, 0, 42);

	printf("3-->|%-0-0-0-0d|<--\n", 6, 3, 0, 42);
	ft_printf("3-->|%-0-0-0-0d|<--\n\n", 6, 3, 0, 42);

	printf("4-->|%0*0*0*0d|<--\n", 6, 3, 0, 42);
	ft_printf("4-->|%0*0*0*0d|<--\n\n", 6, 3, 0, 42);

	printf("5-->|%0*0.*0*0d|<--\n", 6, 3, 0, 42);
	ft_printf("5-->|%0*0.*0*0d|<--\n\n", 6, 3, 0, 42);

	printf("6-->|%0*0*0.*0d|<--\n", 6, 3, 0, 42);
	ft_printf("6-->|%0*0*0.*0d|<--\n\n", 6, 3, 0, 42);

	printf("7-->|%12.10*d|<--\n", 6, 3, 0, 42);
	ft_printf("7-->|%12.10*d|<--\n\n", 6, 3, 0, 42);

	printf("8-->|%00--d|<--\n", 6, 3, 0, 42);
	ft_printf("8-->|%00--d|<--\n\n", 6, 3, 0, 42);

	printf("9-->|%00.-0d|<--\n", 6, 3, 0, 42);
	ft_printf("9-->|%00.-0d|<--\n\n", 6, 3, 0, 42);

	printf("v-->|%101d|<--\n", 6, 3, 0, 42);
	ft_printf("v-->|%101d|<--\n\n", 6, 3, 0, 42);



	//STRINGS:
	printf("\n_____STRINGS_____\n");
	printf("l-->|%10**9.**7.5**.10**2.**.*s|<--\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, "42");
	ft_printf("l-->|%10**9.**7.5**.10**2.**.*s|<--\n\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, "42");

	printf("a-->|%10*9.*7.5s|<--\n", 8, 11, "42");
	ft_printf("a-->|%10*9.*7.5s|<--\n\n", 8, 11, "42");

	printf("b-->|%10*9*5s|<--\n", 8, 11, "42");
	ft_printf("b-->|%10*9*5s|<--\n\n", 8, 11, "42");

	printf("c-->|%10*9*.*7s|<--\n", 4, 6, 3, "42");
	ft_printf("c-->|%10*9*.*7s|<--\n\n", 4, 6, 3, "42");

	printf("x-->|%*10*12s|<--\n", 6, 0, "42");
	ft_printf("x-->|%*10*12s|<--\n\n", 6, 0, "42");

	printf("y-->|%.10*s|<--\n", 0, "42");
	ft_printf("y-->|%.10*s|<--\n\n", 0, "42");

	printf("z-->|%.10*12*s|<--\n", 6, 0, "42");
	ft_printf("z-->|%.10*12*s|<--\n\n", 6, 0, "42");

	printf("0-->|%6..5*s|<--\n", 6, "42");
	ft_printf("0-->|%6..5*s|<--\n\n", 6, "42");

	printf("1-->|%----16..s|<--\n", "42");
	ft_printf("1-->|%----16..s|<--\n\n", "42");

	printf("2-->|%0000s|<--\n", "42");
	ft_printf("2-->|%0000s|<--\n\n", "42");

	printf("3-->|%-0-0-0-0s|<--\n","42");
	ft_printf("3-->|%-0-0-0-0s|<--\n\n", "42");

	printf("4-->|%0*0*0*0s|<--\n", 6, 3, 0, "42");
	ft_printf("4-->|%0*0*0*0s|<--\n\n", 6, 3, 0, "42");

	printf("5-->|%0*0.*0*0s|<--\n", 6, 3, 0, "42");
	ft_printf("5-->|%0*0.*0*0s|<--\n\n", 6, 3, 0, "42");

	printf("6-->|%0*0*0.*0s|<--\n", 6, 3, 0, "42");
	ft_printf("6-->|%0*0*0.*0s|<--\n\n", 6, 3, 0, "42");

	printf("7-->|%12.10*s|<--\n", 6, "42");
	ft_printf("7-->|%12.10*s|<--\n\n", 6, "42");

	printf("8-->|%00--s|<--\n", "42");
	ft_printf("8-->|%00--s|<--\n\n", "42");

	printf("9-->|%00.-0s|<--\n", "42");
	ft_printf("9-->|%00.-0s|<--\n\n", "42");

	printf("v-->|%101s|<--\n", "42");
	ft_printf("v-->|%101s|<--\n\n", "42");



	//LOWER HEX
	printf("\n_____LOW_HEX_____\n");
	printf("l-->|%10**9.**7.5**.10**2.**.*x|<--\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);
	ft_printf("l-->|%10**9.**7.5**.10**2.**.*x|<--\n\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);

	printf("a-->|%10*9.*7.5x|<--\n", 8, 11, 13, 42);
	ft_printf("a-->|%10*9.*7.5x|<--\n\n", 8, 11, 13, 42);

	printf("b-->|%10*9*5x|<--\n", 8, 11, 13, 42);
	ft_printf("b-->|%10*9*5x|<--\n\n", 8, 11, 13, 42);

	printf("c-->|%10*9*.*7x|<--\n", 4, 6, 3, 42);
	ft_printf("c-->|%10*9*.*7x|<--\n\n", 4, 6, 3, 42);

	printf("x-->|%*10*12x|<--\n", 6, 3, 0, 42);
	ft_printf("x-->|%*10*12x|<--\n\n", 6, 3, 0, 42);

	printf("y-->|%.10*x|<--\n", 6, 3, 0, 42);
	ft_printf("y-->|%.10*x|<--\n\n", 6, 3, 0, 42);

	printf("z-->|%.10*12*x|<--\n", 6, 3, 0, 42);
	ft_printf("z-->|%.10*12*x|<--\n\n", 6, 3, 0, 42);

	printf("0-->|%6..5*x|<--\n", 6, 3, 0, 42);
	ft_printf("0-->|%6..5*x|<--\n\n", 6, 3, 0, 42);

	printf("1-->|%----16..x|<--\n", 6, 3, 0, 42);
	ft_printf("1-->|%----16..x|<--\n\n", 6, 3, 0, 42);

	printf("2-->|%0000x|<--\n", 6, 3, 0, 42);
	ft_printf("2-->|%0000x|<--\n\n", 6, 3, 0, 42);

	printf("3-->|%-0-0-0-0x|<--\n", 6, 3, 0, 42);
	ft_printf("3-->|%-0-0-0-0x|<--\n\n", 6, 3, 0, 42);

	printf("4-->|%0*0*0*0x|<--\n", 6, 3, 0, 42);
	ft_printf("4-->|%0*0*0*0x|<--\n\n", 6, 3, 0, 42);

	printf("5-->|%0*0.*0*0x|<--\n", 6, 3, 0, 42);
	ft_printf("5-->|%0*0.*0*0x|<--\n\n", 6, 3, 0, 42);

	printf("6-->|%0*0*0.*0x|<--\n", 6, 3, 0, 42);
	ft_printf("6-->|%0*0*0.*0x|<--\n\n", 6, 3, 0, 42);

	printf("7-->|%12.10*x|<--\n", 6, 3, 0, 42);
	ft_printf("7-->|%12.10*x|<--\n\n", 6, 3, 0, 42);

	printf("8-->|%00--x|<--\n", 6, 3, 0, 42);
	ft_printf("8-->|%00--x|<--\n\n", 6, 3, 0, 42);

	printf("9-->|%00.-0x|<--\n", 6, 3, 0, 42);
	ft_printf("9-->|%00.-0x|<--\n\n", 6, 3, 0, 42);

	printf("v-->|%101x|<--\n", 6, 3, 0, 42);
	ft_printf("v-->|%101x|<--\n\n", 6, 3, 0, 42);


	//PTR
	printf("\n_____PTR_____\n");
	printf("l-->|%10**9.**7.5**.10**2.**.*p|<--\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);
	ft_printf("l-->|%10**9.**7.5**.10**2.**.*p|<--\n\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);

	printf("a-->|%10*9.*7.5p|<--\n", 8, 11, 13, 42);
	ft_printf("a-->|%10*9.*7.5p|<--\n\n", 8, 11, 13, 42);

	printf("b-->|%10*9*5p|<--\n", 8, 11, 13, 42);
	ft_printf("b-->|%10*9*5p|<--\n\n", 8, 11, 13, 42);

	printf("c-->|%10*9*.*7p|<--\n", 4, 6, 3, 42);
	ft_printf("c-->|%10*9*.*7p|<--\n\n", 4, 6, 3, 42);

	printf("x-->|%*10*12p|<--\n", 6, 3, 0, 42);
	ft_printf("x-->|%*10*12p|<--\n\n", 6, 3, 0, 42);

	printf("y-->|%.10*p|<--\n", 6, 3, 0, 42);
	ft_printf("y-->|%.10*p|<--\n\n", 6, 3, 0, 42);

	printf("z-->|%.10*12*p|<--\n", 6, 3, 0, 42);
	ft_printf("z-->|%.10*12*p|<--\n\n", 6, 3, 0, 42);

	printf("0-->|%6..5*p|<--\n", 6, 3, 0, 42);
	ft_printf("0-->|%6..5*p|<--\n\n", 6, 3, 0, 42);

	printf("1-->|%----16..p|<--\n", 6, 3, 0, 42);
	ft_printf("1-->|%----16..p|<--\n\n", 6, 3, 0, 42);

	printf("2-->|%0000p|<--\n", 6, 3, 0, 42);
	ft_printf("2-->|%0000p|<--\n\n", 6, 3, 0, 42);

	printf("3-->|%-0-0-0-0p|<--\n", 6, 3, 0, 42);
	ft_printf("3-->|%-0-0-0-0p|<--\n\n", 6, 3, 0, 42);

	printf("4-->|%0*0*0*0p|<--\n", 6, 3, 0, 42);
	ft_printf("4-->|%0*0*0*0p|<--\n\n", 6, 3, 0, 42);

	printf("5-->|%0*0.*0*0p|<--\n", 6, 3, 0, 42);
	ft_printf("5-->|%0*0.*0*0p|<--\n\n", 6, 3, 0, 42);

	printf("6-->|%0*0*0.*0p|<--\n", 6, 3, 0, 42);
	ft_printf("6-->|%0*0*0.*0p|<--\n\n", 6, 3, 0, 42);

	printf("7-->|%12.10*p|<--\n", 6, 3, 0, 42);
	ft_printf("7-->|%12.10*p|<--\n\n", 6, 3, 0, 42);

	printf("8-->|%00--p|<--\n", 6, 3, 0, 42);
	ft_printf("8-->|%00--p|<--\n\n", 6, 3, 0, 42);

	printf("9-->|%00.-0p|<--\n", 6, 3, 0, 42);
	ft_printf("9-->|%00.-0p|<--\n\n", 6, 3, 0, 42);

	printf("v-->|%101p|<--\n", 6, 3, 0, 42);
	ft_printf("v-->|%101p|<--\n\n", 6, 3, 0, 42);


	//CHAR
	printf("\n_____CHAR_____\n");
	printf("l-->|%10**9.**7.5**.10**2.**.*c|<--\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);
	ft_printf("l-->|%10**9.**7.5**.10**2.**.*c|<--\n\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);

	printf("a-->|%10*9.*7.5c|<--\n", 8, 11, 13, 42);
	ft_printf("a-->|%10*9.*7.5c|<--\n\n", 8, 11, 13, 42);

	printf("b-->|%10*9*5c|<--\n", 8, 11, 13, 42);
	ft_printf("b-->|%10*9*5c|<--\n\n", 8, 11, 13, 42);

	printf("c-->|%10*9*.*7c|<--\n", 4, 6, 3, 42);
	ft_printf("c-->|%10*9*.*7c|<--\n\n", 4, 6, 3, 42);

	printf("x-->|%*10*12c|<--\n", 6, 3, 0, 42);
	ft_printf("x-->|%*10*12c|<--\n\n", 6, 3, 0, 42);

	printf("y-->|%.10*c|<--\n", 6, 3, 0, 42);
	ft_printf("y-->|%.10*c|<--\n\n", 6, 3, 0, 42);

	printf("z-->|%.10*12*c|<--\n", 6, 3, 0, 42);
	ft_printf("z-->|%.10*12*c|<--\n\n", 6, 3, 0, 42);

	printf("0-->|%6..5*c|<--\n", 6, 3, 0, 42);
	ft_printf("0-->|%6..5*c|<--\n\n", 6, 3, 0, 42);

	printf("1-->|%----16..c|<--\n", 6, 3, 0, 42);
	ft_printf("1-->|%----16..c|<--\n\n", 6, 3, 0, 42);

	printf("2-->|%0000c|<--\n", 6, 3, 0, 42);
	ft_printf("2-->|%0000c|<--\n\n", 6, 3, 0, 42);

	printf("3-->|%-0-0-0-0c|<--\n", 6, 3, 0, 42);
	ft_printf("3-->|%-0-0-0-0c|<--\n\n", 6, 3, 0, 42);

	printf("4-->|%0*0*0*0c|<--\n", 6, 3, 0, 42);
	ft_printf("4-->|%0*0*0*0c|<--\n\n", 6, 3, 0, 42);

	printf("5-->|%0*0.*0*0c|<--\n", 6, 3, 0, 42);
	ft_printf("5-->|%0*0.*0*0c|<--\n\n", 6, 3, 0, 42);

	printf("6-->|%0*0*0.*0c|<--\n", 6, 3, 0, 42);
	ft_printf("6-->|%0*0*0.*0c|<--\n\n", 6, 3, 0, 42);

	printf("7-->|%12.10*c|<--\n", 6, 3, 0, 42);
	ft_printf("7-->|%12.10*c|<--\n\n", 6, 3, 0, 42);

	printf("8-->|%00--c|<--\n", 6, 3, 0, 42);
	ft_printf("8-->|%00--c|<--\n\n", 6, 3, 0, 42);

	printf("9-->|%00.-0c|<--\n", 6, 3, 0, 42);
	ft_printf("9-->|%00.-0c|<--\n\n", 6, 3, 0, 42);

	printf("v-->|%101c|<--\n", 6, 3, 0, 42);
	ft_printf("v-->|%101c|<--\n\n", 6, 3, 0, 42);


	//%%
	printf("\n_____PERCENT_____\n");
	printf("l-->|%10**9.**7.5**.10**2.**.*%|<--\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);
	ft_printf("l-->|%10**9.**7.5**.10**2.**.*%|<--\n\n", 26, 23, 21, 19, 17, 15, 13, 12, 9, 7, 5, 42);

	printf("a-->|%10*9.*7.5%|<--\n", 8, 11, 13, 42);
	ft_printf("a-->|%10*9.*7.5%|<--\n\n", 8, 11, 13, 42);

	printf("b-->|%10*9*5%|<--\n", 8, 11, 13, 42);
	ft_printf("b-->|%10*9*5%|<--\n\n", 8, 11, 13, 42);

	printf("c-->|%10*9*.*7%|<--\n", 4, 6, 3, 42);
	ft_printf("c-->|%10*9*.*7%|<--\n\n", 4, 6, 3, 42);

	printf("x-->|%*10*12%|<--\n", 6, 3, 0, 42);
	ft_printf("x-->|%*10*12%|<--\n\n", 6, 3, 0, 42);

	printf("y-->|%.10*%|<--\n", 6, 3, 0, 42);
	ft_printf("y-->|%.10*%|<--\n\n", 6, 3, 0, 42);

	printf("z-->|%.10*12*%|<--\n", 6, 3, 0, 42);
	ft_printf("z-->|%.10*12*%|<--\n\n", 6, 3, 0, 42);

	printf("0-->|%6..5*%|<--\n", 6, 3, 0, 42);
	ft_printf("0-->|%6..5*%|<--\n\n", 6, 3, 0, 42);

	printf("1-->|%----16..%|<--\n", 6, 3, 0, 42);
	ft_printf("1-->|%----16..%|<--\n\n", 6, 3, 0, 42);

	printf("2-->|%0000%|<--\n", 6, 3, 0, 42);
	ft_printf("2-->|%0000%|<--\n\n", 6, 3, 0, 42);

	printf("3-->|%-0-0-0-0%|<--\n", 6, 3, 0, 42);
	ft_printf("3-->|%-0-0-0-0%|<--\n\n", 6, 3, 0, 42);

	printf("4-->|%0*0*0*0%|<--\n", 6, 3, 0, 42);
	ft_printf("4-->|%0*0*0*0%|<--\n\n", 6, 3, 0, 42);

	printf("5-->|%0*0.*0*0%|<--\n", 6, 3, 0, 42);
	ft_printf("5-->|%0*0.*0*0%|<--\n\n", 6, 3, 0, 42);

	printf("6-->|%0*0*0.*0%|<--\n", 6, 3, 0, 42);
	ft_printf("6-->|%0*0*0.*0%|<--\n\n", 6, 3, 0, 42);

	printf("7-->|%12.10*%|<--\n", 6, 3, 0, 42);
	ft_printf("7-->|%12.10*%|<--\n\n", 6, 3, 0, 42);

	printf("8-->|%00--%|<--\n", 6, 3, 0, 42);
	ft_printf("8-->|%00--%|<--\n\n", 6, 3, 0, 42);

	printf("9-->|%00.-0%|<--\n", 6, 3, 0, 42);
	ft_printf("9-->|%00.-0%|<--\n\n", 6, 3, 0, 42);

	printf("v-->|%101%|<--\n", 6, 3, 0, 42);
	ft_printf("v-->|%101%|<--\n\n", 6, 3, 0, 42);
}
