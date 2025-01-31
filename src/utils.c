/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 08:39:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_array_line(int fd)
{
	char	*line;
	char	**array;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
    line = ft_strtrim(line, "\n");
	array = ft_split(line, ' ');
	free (line);
	return (array);
}

float	radiano(float graus)
{
	float	rad;

	rad = (graus / 180) * 3.1415;
	return (rad);
}

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	array_len(char **array)
{
	int		count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}


