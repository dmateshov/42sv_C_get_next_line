# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 23:47:07 by dmatesho          #+#    #+#              #
#    Updated: 2020/02/18 23:58:44 by dmatesho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

FILES = *.o

HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(FILES)
	ranlib $(NAME)

clean:
	/bin/rm -f $(FILES)
	
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
