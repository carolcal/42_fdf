/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:40:56 by cayamash          #+#    #+#             */
/*   Updated: 2024/11/18 18:42:13 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
		i++;
	write (1, s, i);
	return (i);
}

int	ft_putbase(long long n, char *base, int div)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	if (n < 0 && div == 10)
	{
		write (1, "-", 1);
		count ++;
		n = -n;
	}
	c = base[n % div];
	if (n >= div)
		count += ft_putbase(n / div, base, div);
	count += ft_putchar(c);
	return (count);
}

int	ft_putpointer(unsigned long p)
{
	int		i;
	int		count;
	char	*base;
	char	str[17];

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (!p || p == 0)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	while (p > 0)
	{
		str[i] = base[p % 16];
		p /= 16;
		i++;
	}
	count += i;
	i--;
	while (i >= 0)
		write(1, &str[i--], 1);
	return (count);
}
