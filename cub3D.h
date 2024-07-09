#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data
{
	void *mlx;
	void *mlx_win;

} t_data;
void init_window(t_data *data);
int  ft_close(int key);
int key_hook(int key, t_data *data);
void processInput(t_data *data);


#endif