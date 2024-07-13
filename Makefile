##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## emacs
##

NAME := mybookshop

SRC :=	$(wildcard includes/*.hpp) \
		main.cpp \
		$(wildcard src/*.cpp)

OBJ := $(SRC:.c=.o)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)

debug: CFLAGS += -g3
debug: fclean all

all: $(NAME)

clean :
	rm -f *~
	rm -f #*#
	rm -f *.gc*

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
