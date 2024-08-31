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

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("error: canno't initializ windows\n", 2);
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->mlx_3D = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	get_img_data(data, WIDTH, HEIGHT);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_3D, 0, 0);
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

int	main(int ac, char **av)
{
	int		bits_per_pixel;
	int		endian;
	t_data	*data;
	int c;
	int v;

	c = 0;
	v = 0;
	if (ac != 2)
		return (error("Error : Invalid number of parameters !\n"), 1);
	init_data(&data);
	if (!valid_map(av[1], data))
		return (error("Error : Invalid Map !\n"), 1);
	get_cordinate(data);
	data->projection_plan = (WIDTH / 2) / tan(30 * M_PI / 180);
	data->rotationAngle = get_pi_angle(data->map[(int)data->y][(int)data->x]);
	data->params->floor = 0X404040;
	init_window(data);
	data->params->north = mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx,
				"textures/north.xpm", &c, &v), &bits_per_pixel,
			&data->params->linelenght, &endian);
	data->params->south = mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx,
				"textures/south.xpm", &c, &v), &bits_per_pixel,
			&data->params->linelenght, &endian);
	data->params->west = mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx,
				"textures/west.xpm", &c, &v), &bits_per_pixel,
			&data->params->linelenght, &endian);
	data->params->east = mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx,
				"textures/east.xpm", &c, &v), &bits_per_pixel,
			&data->params->linelenght, &endian);
	printf("----> %d\n", c);
	printf("----> %d\n", v);
	data->z = data->y;
	data->f = data->x;
	data->map = map_resize(data->map);
	// for (int i = 0; data->map[i]; i++)
	// {
	// 	printf("%s", data->map[i]);
	// 	printf("$\n");
	// }
	render(data);
	while (1)
	{
		processinput(data);
		mlx_loop(data->mlx);
	}
}
