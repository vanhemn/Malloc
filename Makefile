NAME	=	libmy_malloc_$(shell uname).so
CC		=	gcc
SRC		=	my_malloc.c \
			utils.c

OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-W -Wall -Werror -g -fPIC
RM		=	rm -f

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -shared
			ln -sf $(NAME) libmy_malloc.so

all:
			$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

run:		re
			./malloc

test:		re
			$(CC) -W -Werror -Wall -o malloc main.c

.PHONY:		clean fclean re all run $(NAME)