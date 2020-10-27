# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 14:09:09 by rkochhan          #+#    #+#              #
#    Updated: 2020/10/27 12:53:41 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=

OBJS	= $(SRCS:.c=.o)

INCLUDE	= ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS) $(INCLUDE)
	gcc -Wall -Wextra -Werror -I./ -c $(SRCS)

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

src:
	@ ls | grep .c$ | xargs | sed 's/ /\n\t/g'

.PHONY: all clean fclean re src
