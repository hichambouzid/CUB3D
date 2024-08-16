#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

#include <string.h>
# define FOV 60
# define FOV_RD (FOV * M_PI / 180)
# define CUB_SIZE 20
# define WIDTH 1600
# define HEIGHT 900

typedef enum UPCODE
{
	left,
	right,
	up,
	down,
	t_left,
	t_right
}			t_upcode;

typedef struct s_params
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}		t_params;

typedef struct data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	void		*mlx_img;
	void		*mlx_3D;
	float		rotationAngle;
	int			line_lenght;
	char		*str;
	char		*str1;
	int			coler;
	char		*tmp_str;
	float		x;
	float		y;
	float		f;
	float		z;
	float		angle;
	float		projection_plan;
	float		flag;
	void		*mlx_tmp;
	t_params	*params;
	void	*northh;
	void	*southh;
	void	*westt;
	void	*eastt;
}			t_data;

typedef struct info
{
	int		x;
	int		y;
	char	**map;

}			t_info;

typedef struct collector
{
	int		count;
	void	*garbage[10000];
}			t_collector;

void		init_window(t_data *data);
int			ft_close(int key);
int			key_hook(int key, t_data *data);
int			processinput(t_data *data);
void		get_img_data(t_data *data, int width, int height);
void		put_pixel_to_image(t_data *data, int x, int y, int coler);
int			ft_strleen(char **ptr);
void		ft_putstr_fd(char *str, int fd);
void		get_cordinate(t_data *data);
void		draw_mini_square(t_data *data);
void		render(t_data *data);
void		setup(t_data *data);
int			wall_check(t_data *data, float z, float f);
void		allow_render(t_data *data, int key);
float		get_pi_angle(char c);
void		change_angle(float *angle, int flag, t_data *data);
int			check_coler(t_data *data, int x, int y);
float		render_line(t_data *data, float Angle, int *v_f);
void		draw_fov(t_data *data);
void		*ft_calloc(size_t count, size_t size, t_collector *collector);
void		ft_free(t_collector *collector);
void		draw_ceiling(t_data *data, float end_y, float x);
void		draw_walls(t_data *data, float height_wall, float x);
int     	valid_map(char *file, t_data *data);
int			count_words(char const *s, char c);
char		**ft_split(char const *s, char c);
int			valid_param_helper(char *p, char **param, int *color, int is_color);
int			ft_strcmp(const char *s1, const char *s2);
int			valid_file(char *file);
int			ft_atoi_check(const char *str, int *number);
void		color_rgb(int i, int *color, int c);
void		ft_free_table(char **tab);
int			ft_iswhitespace(int c);
int			ft_allwhitespace(char *s);
#endif