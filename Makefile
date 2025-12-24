NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = main.c \
       get_map.c \
       all_validation.c \
       additional_functions.c \
       mlx_setup.c \
       game_hooks.c \
       free_functions.c \
       put_images.c \
       print_error.c

GNL = get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)


FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a


MLX_FLAGS = -lmlx -lXext -lX11 -lm


all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all
