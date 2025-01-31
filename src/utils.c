/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/30 10:52:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(char *err)
{
	if (err == 0)
		ft_printf("%s", mlx_strerror(mlx_errno));
	else
		ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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
