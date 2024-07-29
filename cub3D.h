#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#define FOV 60
#define CUB_SIZE 60
// #define up 119	
// #define down 115
// #define left 97
// #define right 100
#define WIDTH 1600
#define HEIGHT 900 

typedef enum UPCODE{
	left,
	right,
	up,
	down,
	t_left,
	t_right
} t_upcode;

typedef struct data
{
	void *mlx;
	void *mlx_win;
	char **map;
	void *mlx_img;
	void *mlx_3D;
	float rotationAngle;
    int line_lenght;
    char *str;
	char *str1;
	char *tmp_str;
	float x;
	float y;
	float f;
	float z;
	float angle;
	float projection_plan;
	float flag;
	void *mlx_tmp;
} t_data;

typedef struct info
{
	int x;
	int y;
	char **map;
	
}t_info;

typedef struct collector
{
	int count;
	void *garbage[10000];
} t_collector;

void init_window(t_data *data);
int  ft_close(int key);
int key_hook(int key, t_data *data);
int processInput(t_data *data);
int ft_strlen(char *str);
void  get_img_data(t_data *data, int width, int height);
void put_pixel_to_image(t_data *data, int x, int y, int coler);
int	ft_strleen(char **ptr);
void ft_putstr_fd(char *str, int fd);
void get_cordinate(t_data *data);
void draw_mini_square(t_data *data);
void render(t_data *data);
void setup(t_data *data);
int wall_check(t_data *data,float z, float f);
void allow_render(t_data *data, int key);
float get_pi_Angle(char c);
void change_angle(float *angle, int flag);
int check_coler(t_data *data, int x, int y);
float render_line(t_data *data, float Angle);
void draw_fov(t_data *data);
void *ft_calloc(size_t count, size_t size);
void ft_free(t_collector *collector);

#endif