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

SERVER = server

CLIENT = client

UTILS = utils

CC = gcc

SRCS = 

OUTPUT = -o

LIB = ./minitalk.h

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(NAME): $(OBJ)
	$(COMPILE) $(SFLAGS) -c $< -o $@

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER)
$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT)
$(UTILS):
	$(CC) $(CFLAGS) minitalk_utils.c $(LIB) -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT) $(UTILS)
fclean: clean
re: fclean all

.PHONY: all fclean clean re

NAME = program

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
