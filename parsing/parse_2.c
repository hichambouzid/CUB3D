/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-12 18:52:46 by serraoui          #+#    #+#             */
/*   Updated: 2024-08-12 18:52:46 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_check(const char *str, int *number)
{
	int		i;
	int		sign;
	size_t	n;

	i = 0;
	sign = 1;
	(*number) = 0;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + str[i++] - '0';
	}
	if ((n > INT_MAX && sign == 1) || (n > 2147483648 && sign == -1))
		return (0);
	return ((*number) = n * sign, 1);
}

int	valid_file(char *file)
{
	int	fd;

	if (ft_strncmp(file + (ft_strlen(file) - 4), ".cub", 4))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

void	color_rgb(int i, int *color, int c)
{
	if (i == 0)
		(*color) = c * 256 * 256;
	else if (i == 1)
		(*color) += c * 256;
	else if (i == 2)
		(*color) += c;
}
