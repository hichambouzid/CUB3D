/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:10:24 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/11 22:12:07 by hibouzid         ###   ########.fr       */
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

void	ft_free(t_collector *collector)
{
	int	i;

	i = 0;
	if (i == 0)
		return (free(collector));
	while (i < collector->count)
	{
		free(collector->garbage[i]);
		i++;
	}
	return ;
}

void	ft_free_table(char **tab)
{
	int i;

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

int ft_iswhitespace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
