/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:23 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/17 21:23:18 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_pi_angle(char c)
{
	if (c == 'N')
		return (3 * M_PI / 2);
	if (c == 'S')
		return (M_PI / 2);
	if (c == 'W')
		return (M_PI);
	return (2 * M_PI);
}

void	change_angle(float *angle, int flag, t_data *data)
{
	if (flag == 1)
	{
		*angle += (5 * (M_PI / 180));
		if (*angle > 2 * M_PI)
			*angle -= (2 * M_PI);
	}
	else
	{
		*angle -= (5 * (M_PI / 180));
		if (*angle < 0)
			*angle += (2 * M_PI);
	}
	render(data);
}

void	put_pixel_to_image1(t_data *data, int x, int y, int coler)
{
	char	*tmp;

	tmp = data->str1 + (y * data->line_lenght + 4 * x);
	*(unsigned int *)tmp = coler;
}

void	draw_ceiling(t_data *data, float end_y, float x)
{
	float	start_y;

	(void)end_y;
	start_y = 0;
	while (start_y < HEIGHT / 2)
	{
		put_pixel_to_image1(data, x, start_y, 0x00CCCC);
		start_y++;
	}
}

int  mlx_get_color(t_data *data, int x, int y)
{
	char *coler;
	int pixel_coler;

	coler = (data->text + (y * data->params->linelenght + 4 * x));

	pixel_coler = *(unsigned int *)coler;
	return (pixel_coler);
}

void	draw_walls(t_data *data, float height_wall, float x)
{
	float	start_y;
	float	end_y;
	int	y_text;
	int x_text;
	// float increment;
	int		i;

	i = 0;
	// start_y = height_wall / 2;
	// end_y = ((HEIGHT - height_wall) / 2);
	y_text = 0;
	if (height_wall > HEIGHT)
	{
		start_y = 0;
		end_y = HEIGHT;
		// y_text = (20  * end_y / height_wall);
		y_text = (height_wall - HEIGHT) / 2;
		printf("y---> %d\n", y_text);
	}
	else
	{
		start_y = (HEIGHT - height_wall) / 2;
		end_y = height_wall;
	}
	x_text = data->params->texture_offset;
	// printf("------------------> %d\n", x_text);
	// increment = 20 / end_y;
	
	while (i <= end_y)
	{	
		put_pixel_to_image1(data, x, start_y, mlx_get_color(data, x_text, 20 * y_text / height_wall));
		y_text++;
		start_y++;
		i++;
	}
	// printf("----%f---> %d\n",height_wall, y_text);
}
