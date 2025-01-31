/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:00 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 17:27:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_hex_to_int(char *hex)
{
	int	resp;
	int	num;
	int	i;

	i = 0;
	resp = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i] && hex[i] != ' ' && hex[i] != '\n')
	{
		num = hex[i];
		if (num >= '0' && num <= '9')
			num = num - '0';
		else if (num >= 'a' && num <= 'f')
			num = num - 'a' + 10;
		else if (num >= 'A' && num <= 'F')
			num = num - 'A' + 10;
		else
			handle_error(INVALID_COLOR);
		resp = (resp * 16) + num;
		i++;
	}
	return (resp);
}

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		rgba;
	unsigned char	*ptr;

	rgba = color << 8;
	ptr = (unsigned char *)&rgba;
	*ptr = 0xFF;
	return (rgba);
}

uint32_t	get_color(int z, char *value)
{
	char	*color;

	if (value[1] == ',')
	{
		color = ft_strchr(value, ',');
		color++;
		return (put_alpha(ft_hex_to_int(color)));
	}
	if (z <= 0)
		return (put_alpha(0x0000FF));
	else
		return (put_alpha(0xFFFFFF));
}

uint32_t	gradient(int start_color, int end_color, int grad_len, int position)
{
	double	increment[4];
	int		new[4];
	int		new_color;

	increment[0] = (double)(get_red(end_color) - get_red(start_color))
		/ (double)grad_len;
	increment[1] = (double)(get_green(end_color) - get_green(start_color))
		/ (double)grad_len;
	increment[2] = (double)(get_blue(end_color) - get_blue(start_color))
		/ (double)grad_len;
	increment[3] = (double)(get_alpha(end_color) - get_alpha(start_color))
		/ (double)grad_len;
	new[0] = get_red(start_color) + round(increment[0] * position);
	new[1] = get_green(start_color) + round(increment[1] * position);
	new[2] = get_blue(start_color) + round(increment[2] * position);
	new[3] = get_alpha(start_color) + round(increment[3] * position);
	new_color = get_rgba(new[0], new[1], new[2], new[3]);
	return (new_color);
}
