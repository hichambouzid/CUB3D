/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:23 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/31 21:21:46 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
		put_pixel_to_image1(data, x, start_y, data->params->ceiling);
		start_y++;
	}
}

int	mlx_get_color(t_data *data, int x, int y)
{
	char	*coler;
	int		pixel_coler;

	coler = (data->text + (y * data->params->linelenght + 4 * x));
	pixel_coler = *(unsigned int *)coler;
	return (pixel_coler);
}
