#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct data
{
	void *mlx;
	void *mlx_win;
	char **map;
	void *mlx_img;
    int line_lenght;
    char *str;
	int x;
	int y;

} t_data;

typedef struct info
{
	int x;
	int y;
	char **map;
	
}t_info;

void init_window(t_data *data);
int  ft_close(int key);
int key_hook(int key, t_data *data);
void processInput(t_data *data);
int ft_strlen(char *str);
void  get_img_data(t_data *data, int width, int height);
void put_pixel_to_image(t_data *data, int x, int y, int coler);
int	ft_strleen(char **ptr);
void ft_putstr_fd(char *str, int fd);
void get_cordinate(t_data *data);
void draw_mini_square(t_data *data);
#endif