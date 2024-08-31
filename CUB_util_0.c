/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:59:25 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/16 18:22:37 by hibouzid         ###   ########.fr       */
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

int	wall_check(t_data *data, float z, float f)
{
	int	j;
	int	i;

	j = z * 20 + 8;
	while (j < (z * 20) + 14)
	{
		i = f * 20 + 8;
		while (i < (f * 20) + 14)
		{
			if (data->map[(int)(j / 20)][(int)(i / 20)] == '1')
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
