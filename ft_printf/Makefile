CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putuhexa.c ft_putchar.c  ft_putnbr.c  ft_putstr.c ft_puthexa.c  ft_putptr.c  ft_putuns.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
		ar rcs $@ $^

clean: 
		rm -f $(OBJS) 

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re 