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


#endif