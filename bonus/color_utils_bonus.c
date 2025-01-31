/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:12:06 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 16:12:06 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	get_alpha(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_rgba(int red, int green, int blue, int alpha)
{
	return (((alpha) << 24) + ((red) << 16) + ((green) << 8) + (blue));
}
