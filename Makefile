# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 14:46:34 by nmtimkul          #+#    #+#              #
#    Updated: 2017/11/17 13:24:02 by nmtimkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c\
	  find_player.c\
	  get_info.c\
	  check_piece.c\
	  save_map.c\
	  ft_player.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror $(OBJ) libft/libft.a -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all
