NAME = libftprintf.a

CC = cc

OBJ = ${SRC:%.c=%.o}

CFLAGS = -Wall -Wextra -Werror

SRC = ft_putaddr.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunbr.c ft_printf.c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $?

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
