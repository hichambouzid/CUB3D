/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:10:46 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/31 13:26:22 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char *ret_new_line(char *str)
{
	return (ft_strjoin(str, " 1111111111111111111111111111111111"));
}

char **map_resize(char **map)
{
	int i;
	int len;
	char **new;
	int j;
	
	j = 0;
	new = (char **)ft_calloc(10000, sizeof(char *), NULL);
	len = ft_strleen(map);
	i = 0;
	new[i] = ft_strdup("111111111111111111111111111111111111111111111111111111");
	while (j < len)
	{
		map[j] = ret_new_line(map[j]);
		new[i] = ft_strdup(map[j]);
		i++;
		j++;
	}
	// ft_free(m);
	new[i] = ft_strdup("111111111111111111111111111111111111111111111111111111");
	return (new);
}