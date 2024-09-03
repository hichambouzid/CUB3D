/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:19:15 by hibouzid          #+#    #+#             */
/*   Updated: 2024/09/03 20:23:00 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int raycasting(t_data *data)
{
	int dx = cos(data->angle);
	int dy = sin(data->angle);
	int tmp_a = 32 + (data->f * (CUB_SIZE));
	int tmp_b = 32 + (data->z * (CUB_SIZE));
	int a = 32 + (data->f * (CUB_SIZE));
	int b = 32 + (data->z * (CUB_SIZE));
	int step_x;
	int step_y;
	float deltax;
	float deltay;
	float in_x;
	float in_y;
	float distx;
	float disty;
	deltax = fabs(CUB_SIZE / cos(data->angle));
	deltay = fabs(CUB_SIZE / sin(data->angle));

	if (cos(data->angle) < 0)
	{
		step_x = -CUB_SIZE;
		in_x = (tmp_a - floor(tmp_a) * deltax) ;	
	}
	else
	{
		step_x = CUB_SIZE;
		in_x = ((ceil(tmp_a) - tmp_a) * deltax);	
	}
	if (sin(data->angle) < 0)
	{
		step_y = -CUB_SIZE;
		in_y = (tmp_b - floor(tmp_b) * deltay) ;	
	}
	else
	{
		step_y = CUB_SIZE;
		in_y = ((ceil(tmp_b) - tmp_b) * deltay);	
	}
	distx = (in_x - tmp_a) / fabs(dx);
	disty = (in_y - tmp_b) / fabs(dy);
	while (1)
	{
		if (data->map[(int)in_y / CUB_SIZE][(int)in_y / CUB_SIZE] == '1' ||
			data->map[(int)in_y / CUB_SIZE][(int)in_y / CUB_SIZE] == ' ')
			break ;
			if (distx < disty)
			{
				a = in_x;
				b = tmp_b + (a - tmp_a) * (dy / dx);
				in_x += step_x;
				distx += deltax;
			}
			else 
			{
				
				b = in_y;
				a = tmp_a + (b - tmp_b) * (dy / dx);
				in_y += deltay;
				disty += step_y;
			}
	}
	return (sqrt(a - tmp_a) * (a - tmp_a) * (b - tmp_b) * (b - tmp_b));
}