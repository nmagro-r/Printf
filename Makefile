
NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra
CC = cc

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c  ft_ptr_hex.c ft_putnbr_unsigned.c ft_hex_low.c ft_hex_upp.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.Phony: re fclean clean all