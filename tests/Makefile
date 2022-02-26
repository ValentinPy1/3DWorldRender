##
## EPITECH PROJECT, 2021
## common
## File description:
## Makefile
##

SRC	=	test1.c	\

NAME	=	unit_tests

CPPFLAGS	=	-I ../includes/ --coverage

LDFLAGS	=	-L ../lib/ -lmy -lcriterion

CFLAGS	=	-Wall -Wextra -g

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
	./$(NAME)

cov:	$(tests_run)
	gcovr --exclude $(NAME)

fclean:
	rm -f $(NAME)