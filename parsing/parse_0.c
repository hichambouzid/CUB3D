/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:03:47 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/24 15:04:14 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

int	valid_param(char *p, t_params *params)
{
	char	**psp;
	int		ret;

	p[ft_strlen(p) - 1] = '\0';
	psp = ft_split(p, ' ');
	if (count_words(p, ' ') != 2)
		return (ft_free_table(psp), 0);
	if (!ft_strcmp(psp[0], "NO") && !params->north)
		ret = valid_param_helper(psp[1], &params->north, NULL, 0);
	else if (!ft_strcmp(psp[0], "SO") && !params->south)
		ret = valid_param_helper(psp[1], &params->south, NULL, 0);
	else if (!ft_strcmp(psp[0], "WE") && !params->west)
		ret = valid_param_helper(psp[1], &params->west, NULL, 0);
	else if (!ft_strcmp(psp[0], "EA") && !params->east)
		ret = valid_param_helper(psp[1], &params->east, NULL, 0);
	else if (!ft_strcmp(psp[0], "F") && params->floor == -1)
		ret = valid_param_helper(psp[1], NULL, &params->floor, 1);
	else if (!ft_strcmp(psp[0], "C") && params->ceiling == -1)
		ret = valid_param_helper(psp[1], NULL, &params->ceiling, 1);
	else
		return (ft_free_table(psp), 0);
	if (!ret)
		return (ft_free_table(psp), 0);
	return (ft_free_table(psp), 1);
}

int	valid_map_components_helper(char **map, int i, int j)
{
	if (map[i][j] == '0' || ft_strchr("NSWE", map[i][j]))
	{
		if (!map[i - 1] || (map[i - 1] && !map[i - 1][j]) || (map[i - 1]
				&& map[i - 1][j] && ft_iswhitespace(map[i - 1][j])))
			return (0);
		if (!map[i + 1] || (map[i + 1] && !map[i + 1][j]) || (map[i + 1]
				&& map[i + 1][j] && ft_iswhitespace(map[i + 1][j])))
			return (0);
		if (!map[i] || (map[i] && !map[i][j - 1]) || (map[i] && map[i][j - 1]
				&& ft_iswhitespace(map[i][j - 1])))
			return (0);
		if (!map[i] || (map[i] && !map[i][j + 1]) || (map[i] && map[i][j + 1]
				&& ft_iswhitespace(map[i][j + 1])))
			return (0);
	}
	return (1);
}

int	valid_map_components(char **map)
{
	int	p;
	int	i;
	int	j;

	p = 0;
	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" NSWE10", map[i][j]))
				return (0);
			if (ft_strchr("NSWE", map[i][j]))
				p++;
			if (!valid_map_components_helper(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (p == 1);
}

int	valid_map_helper(t_data *data, int fd, int flag, int params)
{
	char	*rline;
	int		i;

	i = 0;
	rline = get_next_line(fd);
	while (rline)
	{
		if ((!ft_strcmp(rline, "\n") || ft_allwhitespace(rline)) && flag)
			return (free(rline), 0);
		else if (ft_strcmp(rline, "\n") && !flag && params != 6)
		{
			if (!valid_param(rline, data->params))
				return (free(rline), 0);
			(params)++;
		}
		else if (params == 6 && ft_strcmp(rline, "\n"))
		{
			flag = 1;
			rline[ft_strlen(rline) - 1] = '\0';
			data->map[i++] = ft_strdup(rline);
		}
		free(rline);
		rline = get_next_line(fd);
	}
	return (1);
}

int	valid_map(char *file, t_data *data)
{
	int		fd;
	int		flag;
	int		params;

	fd = valid_file(file);
	if (!fd)
		return (0);
	params = 0;
	flag = 0;
	if (!valid_map_helper(data, fd, flag, params))
		return (0);
	return (valid_map_components(data->map));
}
