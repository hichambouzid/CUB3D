/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:14:26 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/16 18:22:25 by hibouzid         ###   ########.fr       */
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

int	get_appropriate_texture(t_data *data, float angle, int v_h)
{
	(void)data;
	if (v_h == 1)
	{
		if ((angle > 0 && angle < M_PI) || (angle > M_PI * 2 && angle < (400
					* M_PI / 180)))
			return (0XCCE5FF);
		else
			return (0X66FF66);
	}
	if (v_h == 0)
	{
		if ((angle > M_PI / 2 && angle < 3 * M_PI / 2))
			return (0XA0A0A0);
		else
			return (0X7F00FF);
	}
	return (0);
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
		data->coler = get_appropriate_texture(data, tmp, v_h);
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
