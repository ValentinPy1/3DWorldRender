##
## EPITECH PROJECT, 2021
## common
## File description:
## Makefile
##

SRCPATH	=	src/

SRC	=	$(SRCPATH)main.c	\
		$(SRCPATH)csfmlprocess.c	\
		$(SRCPATH)setup_map.c	\
		$(SRCPATH)projection.c	\
		$(SRCPATH)manage_input.c	\
		$(SRCPATH)mouse_input.c	\

NAME	=	my_world

CPPFLAGS	=	-I includes/

LDFLAGS	=	-L lib/ -lmy -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

LIBPATH	=	lib/my/

LIBNAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(LIBNAME)
	gcc $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

tests_run:	$(LIBNAME)
	make -C tests/

cov:
	make -C tests/ cov

$(LIBNAME):
	make -C $(LIBPATH)

clean:
	make -C $(LIBPATH) clean
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f ./lib/$(LIBNAME)
	rm -f $(TEST_NAME)
	make -C tests/ fclean

re:	fclean	all
