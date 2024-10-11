NAME = cub3D

CFLAGS = -g3 -Wall -Wextra -Werror  -I ./minilibx_mms_20200219 -Imlx_linux -O3

CFILS = cub3d/key_h00k.c  main.c  cub3d/mlx_img.c cub3d/CUB_util_0.c cub3d/render_all.c cub3d/CUB_util_1.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		parsing/parse_0.c parsing/parse_1.c parsing/parse_2.c parsing/parse_3.c parsing/garbage_collector.c \
		cub3d/CUB_util_2.c cub3d/CUB_utils.c raycasting.c helper_raycasting.c


OBJS = $(CFILS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
		cc $(OBJS) -g3 -fsanitize=leak -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all