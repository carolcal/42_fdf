/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:00 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 10:17:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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