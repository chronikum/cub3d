/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:04:28 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 17:01:44 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strjoin_dif(char const *s1, char const *s2)
{
	char			*d;
	unsigned int	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	d = xmalloc(sizeof(char) * (size));
	ft_memcpy(d, (const void *) s1, ft_strlen((char *) s1));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	d[size - 1] = '\0';
	free((char *)s1);
	return (d);
}

char	*ft_substr_dif(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	c;

	c = 0;
	d = (char *) xmalloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (d);
	while (c < len)
	{
		d[c] = s[c + start];
		c++;
	}
	d[c] = '\0';
	return (d);
}

char	*ft_strdup_dif(const char *s1)
{
	char	*dest;

	dest = xmalloc(ft_strlen((char *)s1) + 1);
	ft_memcpy((char *) dest, (char *) s1, ft_strlen(s1));
	dest[ft_strlen(s1)] = '\0';
	return (dest);
}
