# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 14:09:09 by rkochhan          #+#    #+#              #
#    Updated: 2021/03/11 22:06:04 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= ./libft

SRC		= ft_printf.c \
		ft_printf_conversion.c \
		ft_printf_char_str.c \
		ft_printf_int_base.c \
		ft_printf_print_utils.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= -I. -I$(LIBFT)

.c.o:
	gcc -Wall -Werror -Wextra $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ cp $(LIBFT)/libft.a $(NAME)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

src:
	@ ls | grep "\.c"$ | grep -v main.c | xargs | sed 's/ / \\\n\t\t/g'

.PHONY: all clean fclean re src
