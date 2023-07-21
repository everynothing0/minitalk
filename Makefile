# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 16:56:56 by cde-voog          #+#    #+#              #
#    Updated: 2023/07/21 19:43:28 by cde-voog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program.a

COMPILE = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = utils.c client.c server.c

OUTPUT = -o

LIBRARY = rc program.a ft_*.o

OBJ = $(SRCS:.c=.o)

CLEANCMD = rm -rf *.o
FCLEANCMD = rm -rf *.a

$(NAME):$(OBJ)
	$(COMPILE) $(CFLAG) -c $(SRC)
	ar rcs program.a ft_*.o

all:$(NAME)

%.o:%.c
	$(COMPILE) $(CFLAG) -c $< -o $@

clean:
	$(CLEANCMD)

fclean: clean
	$(FCLEANCMD)

re: fclean all
