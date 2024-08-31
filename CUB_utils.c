/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:10:46 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/31 15:40:12 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_line(int nbr)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (nbr + 2));
	if (!ptr)
		return (NULL);
	while (i < nbr + 1)
		ptr[i++] = '1';
	ptr[i] = 0;
	return (ptr);
}

char	**map_resize(char **map)
{
	int		i;
	int		len;
	char	**new;
	char	*tmp;
	int		j;

	j = 0;
	new = (char **)ft_calloc(10000, sizeof(char *), NULL);
	len = ft_strleen(map);
	i = 0;
	new[i] = get_line(ft_strlen(map[0]));
	tmp = get_line(1e3);
	while (j < len)
	{
		map[j] = ft_strjoin(map[i], tmp);
		new[i] = ft_strdup(map[j]);
		i++;
		j++;
	}
	free(tmp);
	new[i] = get_line(1e3);
	return (new);
}

void	draw_walls(t_data *data, float height_wall, float x)
{
	float	start_y;
	float	end_y;
	int		y_text;
	int		x_text;
	int		i;

	i = 0;
	y_text = 0;
	if (height_wall > HEIGHT)
	{
		start_y = 0;
		end_y = HEIGHT;
		y_text = (height_wall - HEIGHT) / 2;
	}
	else
	{
		start_y = (HEIGHT - height_wall) / 2;
		end_y = height_wall;
	}
	x_text = data->params->texture_offset;
	while (i++ <= end_y)
		put_pixel_to_image1(data, x, start_y++, mlx_get_color(data, x_text,
				CUB_SIZE * y_text++ / height_wall));
}
