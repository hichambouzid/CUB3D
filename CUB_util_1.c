/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:23 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/02 12:17:03 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_pi_Angle(char c)
{
	if (c == 'N')
		return (3 * M_PI / 2);
	if (c == 'S')
		return (M_PI / 2);
	if (c == 'W')
		return (M_PI);
	return (2 * M_PI);
}

void	change_angle(float *angle, int flag)
{
	if (flag == 1)
	{
		*angle += 5 * (M_PI / 180);
		if (*angle > 2 * M_PI)
			*angle = 0;
	}
	else
	{
		*angle -= 4 * (M_PI / 180);
		if (*angle < 0)
			*angle = 2 * M_PI;
	}
}

// void get_s(float Angle, float *start)
// {
//     float tmp;

//     tmp = (30 * PI) / 180;
//     *start = Angle;

// }

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
		put_pixel_to_image1(data, x, start_y, 0x00FF0000);
		start_y++;
	}
}

void	draw_walls(t_data *data, float height_wall, float x)
{
	float	start_y;
	float	end_y;
	int		i;

	i = 0;
	// float tmp_height;
	start_y = height_wall / 2;
	end_y = ((HEIGHT - height_wall) / 2);
	if (height_wall >= HEIGHT)
	{
		start_y = 0;
		end_y = HEIGHT;
	}
	else
	{
		// tmp_height = (height_wall * HEIGHT / 100);
		start_y = (HEIGHT - height_wall) / 2;
		end_y = height_wall;
	}
	while (i <= end_y)
	{
		put_pixel_to_image1(data, x, start_y, 0);
		start_y++;
		i++;
	}
}

void	draw_fake_3D(t_data *data, float hit, float x)
{
	float	height_wall;

	// float end_y;
	height_wall = (CUB_SIZE / hit) * data->projection_plan;
	// height_wall /= CUB_SIZE;
	// printf("height %f\n", height_wall);
	draw_ceiling(data, hit, x);
	draw_walls(data, floorf(height_wall), x);
	// draw_walls(data, floorf(height_wall * 1100 / 100), x);
}

// void correct_3D(t_data *data, int y)
// {

// }

float	nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_fov(t_data *data)
{
	float tmp;
	float hit;

	float f;
	// int i = 0;
	f = 0;
	tmp = data->rotationAngle - ((30 * M_PI) / 180);
	while (tmp <= data->rotationAngle + ((30 * M_PI) / 180))
	{
		hit = render_line(data, tmp);
		// printf("-------------------> %f\n", hit);
		data->angle = tmp - data->rotationAngle;
		draw_fake_3D(data, hit * cos(nor_angle(tmp - data->rotationAngle)), f);
		tmp +=  FOV_RD / WIDTH;
		f++;
	}
	// // tmp = data->rotationAngle - ((30 * M_PI) / 180);
	// i = 0;
	// while (i < HEIGHT)
	// {
	//     if (!check_coler(data, 0, i))
	//     {
	//         correct_3D(data, i);
	//     }
	//     i++;
	// }

	// printf("=======================>%d\n", f);
	// tmp = data->rotationAngle - ((30 * M_PI) / 180);
	// while (tmp < data->rotationAngle)
	// {
	//     render_line(data, tmp);
	//     tmp += 0.001;
	// }
	// render(data);
}