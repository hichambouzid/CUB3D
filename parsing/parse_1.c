/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-12 18:48:47 by serraoui          #+#    #+#             */
/*   Updated: 2024-08-12 18:48:47 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	chuncks_number;

	i = 0;
	chuncks_number = 0;
	if (*s == '\0')
		return (chuncks_number);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			chuncks_number += 1;
		i++;
	}
	if (s[i - 1] != c)
		chuncks_number += 1;
	return (chuncks_number);
}

static int	count_word_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	*free_allocation(char **s, int count)
{
	while (count >= 0)
	{
		free(s[count]);
		count--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		offset;
	int		j;
	int		i;

	offset = 0;
	i = 0;
	str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (i < count_words(s, c))
	{
		str[i] = malloc((count_word_len(&s[offset], c) + 1) * sizeof(char));
		if (!str[i])
			return (free_allocation(str, i));
		j = 0;
		while (s[offset] == c)
			offset++;
		while (s[offset] && s[offset] != c)
			str[i][j++] = s[offset++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

int	valid_param_helper(char *p, char **param, int *color, int is_color)
{
	char	**rgb;
	size_t	i;
	int		c;

	if (!is_color)
		(*param) = ft_strdup(p);
	else
	{
		rgb = ft_split(p, ',');
		i = -1;
		if (count_words(p, ',') != 3)
			return (ft_free_table(rgb), 0);
		while (++i < 3)
		{
			if (!ft_atoi_check(rgb[i], &c) || c < 0 || c > 255)
				return (ft_free_table(rgb), 0);
			color_rgb(i, color, c);
		}
		ft_free_table(rgb);
	}
	return (1);
}
