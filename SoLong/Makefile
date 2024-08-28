SRCS =		so_long.c \
			so_long_free_func.c \
			so_long_get_func.c \
			so_long_main.c \
			so_long_map_check.c \
			so_long_map_check2.c \
			so_long_utils.c

HEADER = so_long.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address 
LIB_DIR = libft
MLX_DIR = mlx

OBJS = $(SRCS:.c=.o)

TARGET = so_long

all: $(TARGET)


$(TARGET): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L$(LIB_DIR) -lXext -lX11 -lm -lz -lft -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	make clean -C $(MLX_DIR)
	make fclean -C $(LIB_DIR)
	rm -f $(TARGET)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
