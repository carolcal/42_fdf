/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:13:48 by cayamash          #+#    #+#             */
/*   Updated: 2024/10/28 14:08:20 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while ((unsigned char)s[slen] != (unsigned char)c && slen > 0)
		slen--;
	if ((unsigned char)s[slen] == (unsigned char)c)
		return ((char *)s + slen);
	return (NULL);
}
