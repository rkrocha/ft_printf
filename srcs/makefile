# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 14:09:09 by rkochhan          #+#    #+#              #
#    Updated: 2020/12/07 23:16:29 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= ./libft

SRC	= ft_printf.c

OBJ	= $(SRC:.c=.o)

INCLUDE	= -I. -I$(LIBFT)

all: $(NAME)

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ cp $(LIBFT)/libft.a ./$(NAME)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "Made $(value NAME)"

$(OBJ): $(SRC) ft_printf.h $(LIBFT)/libft.h
	@ gcc -Wall -Wextra -Werror $(INCLUDE) -lft -c $(SRC)

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

src:
	@ ls | grep .c$ | xargs | sed 's/ / \\\n\t/g'

.PHONY: all clean fclean re src
