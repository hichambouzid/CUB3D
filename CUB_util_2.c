/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:14:26 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/12 20:58:18 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_fake_3d(t_data *data, float hit, float x)
{
	float	height_wall;

	height_wall = (CUB_SIZE / hit) * data->projection_plan;
	draw_ceiling(data, hit, x);
	draw_walls(data, floorf(height_wall), x);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void *get_appropiate_texture(t_data *data, float angle, int v_h)
{
	if (v_h == 1)
	{
		if (angle >= 0 && angle <= M_PI)
		{
		// texture north
		return ();
		}
		else
		{
			//south
			return()
		}
	}
	if (v_h == 0)
	{
		if (angle >= M_PI / 2 && angle <= 3 * M_PI / 2)
		{
		// texture left
		return ();
		}
		else
		{//right
			return()
		}
	}

}

void	draw_fov(t_data *data)
{
	float	tmp;
	float	hit;
	int		v_h;
	float	f;

	f = 0;
	tmp = data->rotationAngle - ((30 * M_PI) / 180);
	while (tmp <= data->rotationAngle + ((30 * M_PI) / 180))
	{
		hit = render_line(data, tmp, &v_h);
		data->img = get_appropriate_texture(data, tmp, v_h);
		data->angle = tmp - data->rotationAngle;
		draw_fake_3d(data, hit * cos(nor_angle(data->angle)), f);
		tmp += FOV_RD / WIDTH;
		f++;
	}
}

void	draw_mini_square(t_data *data)
{
	float	j;
	float	i;

	j = data->z * 20 + 8;
	while (j < (data->z * 20) + 14)
	{
		i = data->f * 20 + 8;
		while (i < (data->f * 20) + 14)
		{
			put_pixel_to_image(data, i, j, 0x00FF0000);
			i++;
		}
		j++;
	}
}

int	wall_check(t_data *data, float z, float f)
{
	int		j;
	int		i;
	char	*tmp;

	j = z * 20 + 8;
	while (j < (z * 20) + 14)
	{
		i = f * 20 + 8;
		while (i < (f * 20) + 14)
		{
			tmp = data->str + (int)(j * data->line_lenght + 4 * i);
			if (*(unsigned int *)tmp == 0)
			{
				printf("hee hee ]\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
