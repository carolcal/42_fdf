/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:18:06 by cayamash          #+#    #+#             */
/*   Updated: 2024/10/18 13:48:19 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write (fd, &c, 1);
}

/*int	main(int argc, char *argv[])
{
	int	fd;
	if (argc == 3)
	{
		fd = open(argv[1], O_WRONLY);
		ft_putchar_fd(argv[2][0], fd);
		close(fd);
	}
	return (0);
}*/
