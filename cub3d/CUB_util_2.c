/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:14:26 by hibouzid          #+#    #+#             */
/*   Updated: 2024/10/11 15:16:54 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_fake_3d(t_data *data, float hit, float x)
{
	float	height_wall;
	int		i;

	i = 0;
	height_wall = (CUB_SIZE / hit) * data->projection_plan;
	draw_ceiling(data, hit, x);
	draw_walls(data, height_wall, x);
	if (x == WIDTH)
	{
		while (i < HEIGHT)
			put_pixel_to_image1(data, 0, i++, 0);
	}
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

char	*get_appropriate_texture(t_data *data, float angle, int v_h)
{
	(void)data;
	(void)angle;
	if (v_h == 1 || v_h == 3)
	{
		if (v_h == 1)
			return (data->params->north);
		if (v_h == 3)
			return (data->params->south);
	}
	if (v_h == 2 || v_h == 4)
	{
		if (v_h == 2)
			return (data->params->east);
		if (v_h == 4)
			return (data->params->west);
	}
	return (data->params->west);
}

void	draw_fov(t_data *data)
{
	float	tmp;
	float	hit;
	int		v_h;
	float	f;

	f = 0;
	tmp = data->rotation_angle - ((30 * M_PI) / 180);
	while (tmp <= data->rotation_angle + ((30 * M_PI) / 180))
	{
		hit = render_line(data, tmp, &v_h);
		data->text = get_appropriate_texture(data, tmp, v_h);
		data->angle = tmp - data->rotation_angle;
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
