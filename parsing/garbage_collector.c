/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:10:24 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/31 21:31:46 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	*ft_calloc(size_t count, size_t size, t_collector *collector)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	if (collector)
		collector->garbage[collector->count++] = ptr;
	return (ptr);
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	if (ft_strleen(ptr) == 0)
		return (free(ptr));
	while (i < ft_strleen(ptr))
	{
		free(ptr[i]);
		i++;
	}
	return ;
}

void	ft_free_table(char **tab)
{
	int	i;

	i = 0;
	if (!tab && !(*tab))
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	valid_color_pre(char *p, int is_color)
{
	int		c_count;
	int		i;

	c_count = 0;
	if (is_color < 4)
		return (0);
	i = 0;
	while (p && p[i])
	{
		if (',' == p[i++])
			c_count++;
	}
	if (c_count != 2)
		return (0);
	return (1);
}
