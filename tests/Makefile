NAME = test_printf

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = test_main.c test_main_utils1.c test_main_utils2.c

OBJ = ${SRC:%.c=%.o}

LIBDIR = ..

LIB = $(LIBDIR)/libftprintf.a

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

run: all
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re $(LIB)
