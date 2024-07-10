# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 14:27:32 by gabguerr          #+#    #+#              #
#    Updated: 2024/07/07 16:45:22 by gabguerr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE  =  sources/operations/*.c \
		   sources/sorting/*.c \
		   sources/utils/*.c \
		   sources/main.c

$(NAME):
#	norminette $(SOURCE)
	$(CC) $(FLAGS) $(SOURCE) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf sources/*.o
	@rm -rf sources/operations/*.o
	@rm -rf sources/sorting/*.o
	@rm -rf sources/utils/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
