#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>

typedef struct data
{
	void *mlx;
	void *mlx_win;

} t_data;
void init_window(t_data *data);
#endif