NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -I ./minilibx_mms_20200219 -Imlx_linux -O3

CFILS = 

OBJS = $(CFILS:.c=.o)

all: $(OBJS)
	cc -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean