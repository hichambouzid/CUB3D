/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:59:25 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/02 12:23:00 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strleen(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

void	get_cordinate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				data->x = j;
				data->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	data->x = 0;
	data->y = 0;
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
	int j;
	int i;
	char *tmp;

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