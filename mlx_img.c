/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:11:06 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/16 23:23:27 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel_to_image(t_data *data, int x, int y, int coler)
{
	char	*tmp;

	tmp = data->str1 + (y * data->line_lenght + 4 * x);
	*(unsigned int *)tmp = coler;
}

void	get_img_data(t_data *data, int width, int height)
{
	int	bits_per_pixel;
	int	endian;
	int	i;

	i = 0;
	data->str1 = mlx_get_data_addr(data->mlx_3D, &bits_per_pixel,
			&data->line_lenght, &endian);
	while (i < height * width)
		*((unsigned int *)data->str1 + i++) = data->params->floor;
}

void	change_cordinate(t_data *data, int key, float *tmp_x, float *tmp_y)
{
	if (key == 97)
	{
		*tmp_x = cos(data->rotationAngle - M_PI_2) * 0.35;
		*tmp_y = sin(data->rotationAngle - M_PI_2) * 0.35;
	}
	else if (key == 100)
	{
		*tmp_x = cos(data->rotationAngle + M_PI_2) * 0.35;
		*tmp_y = sin(data->rotationAngle + M_PI_2) * 0.35;
	}
	else if (key == 119)
	{
		*tmp_x = cos(data->rotationAngle) * 0.35;
		*tmp_y = sin(data->rotationAngle) * 0.35;
	}
	else if (key == 115)
	{
		*tmp_x = -cos(data->rotationAngle) * 0.35;
		*tmp_y = -sin(data->rotationAngle) * 0.35;
	}
	return ;
}

void	allow_render(t_data *data, int key)
{
	float	tmp_x;
	float	tmp_y;

	change_cordinate(data, key, &tmp_x, &tmp_y);
	if (!wall_check(data, tmp_y + data->z, tmp_x + data->f))
		return ;
	data->z += tmp_y;
	data->f += tmp_x;
	render(data);
	return ;
}
