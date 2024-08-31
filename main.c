/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:55:30 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/31 15:57:31 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("error: can't initialise windows\n", 2);
		return (0);
	}
	if (!valid_textures(data))
		return (0);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->mlx_3D = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	get_img_data(data, WIDTH, HEIGHT);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_3D, 0, 0);
	return (1);
}

int	get_coler(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xFBF7F4);
	if (c == '1')
		return (0);
	return (0x00808080);
}

void	init_data(t_data **data)
{
	(*data) = (t_data *)ft_calloc(1, sizeof(t_data), NULL);
	(*data)->map = (char **)ft_calloc(10000, sizeof(char *), NULL);
	(*data)->params = (t_params *)ft_calloc(1, sizeof(t_params), NULL);
	(*data)->params->north = NULL;
	(*data)->params->south = NULL;
	(*data)->params->west = NULL;
	(*data)->params->east = NULL;
	(*data)->params->floor = -1;
	(*data)->params->ceiling = -1;
}

void	error(char *err)
{
	int	i;

	i = 0;
	while (err[i])
		i++;
	write(2, err, i);
}

int	valid_texture(t_data *data, char **param)
{
	int c,v;
	int	bpp;
	int	endian;

	c = 0;
	v = 0;
	if (!mlx_xpm_file_to_image(data->mlx, *param, &c, &v))
		return (printf("Error : Invalid texture file %s !\n", *param), 0);
	*param = mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx, *param, &c, &v), &bpp, &data->params->linelenght, &endian);
	return (1);
}

int	valid_textures(t_data *data)
{
	if (valid_texture(data, &data->params->north) &&
		valid_texture(data, &data->params->south) &&
		valid_texture(data, &data->params->west) &&
		valid_texture(data, &data->params->east)
	)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (error("Error : Invalid number of parameters !\n"), 1);
	init_data(&data);
	if (!valid_map(av[1], data))
		return (error("Error : Invalid Map !\n"), 1);
	get_cordinate(data);
	if (!init_window(data))
		return (1);
	data->projection_plan = (WIDTH / 2) / tan(30 * M_PI / 180);
	data->rotationAngle = get_pi_angle(data->map[(int)data->y][(int)data->x]);
	data->z = data->y;
	data->f = data->x;
	data->map = map_resize(data->map);
	render(data);
	while (1)
	{
		processinput(data);
		mlx_loop(data->mlx);
	}
}
