# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 14:09:09 by rkochhan          #+#    #+#              #
#    Updated: 2020/12/17 22:06:04 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= ./libft

SRC		= ft_printf.c

OBJ		= ./objs/$(SRC:.c=.o)

INCLUDE	= -I. -I$(LIBFT)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)							#CHECK RELINKAGE
	@ make -s -C $(LIBFT)
	@ cp $(LIBFT)/libft.a $(NAME)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "Made $(value NAME)"

$(OBJ):
	@ gcc -Wall -Wextra -Werror $(INCLUDE) -lft -c $(SRC) -o $(OBJ)

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

src:
	@ ls | grep .c$ | grep -v main.c | xargs | sed 's/ / \\\n\t\t/g'

.PHONY: all clean fclean re src
