/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:34:24 by ysonmez           #+#    #+#             */
/*   Updated: 2022/02/09 15:24:15 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	checkchar(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ccount(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s1[i] == '\0')
		return (0);
	while (s1[i] != '\0' && checkchar(s1[i], set) == 1)
	{
		count++;
		i++;
	}
	if (i == ft_strlen(s1))
		return (0);
	while (s1[i] != '\0')
		i++;
	i--;
	while (s1[i] != '\0' && i > 0 && checkchar(s1[i], set) == 1)
	{
		count++;
		i--;
	}
	count = ft_strlen(s1) - count;
	return (count);
}

static size_t	position(char const *s, char const *set, int pos)
{
	size_t	i;

	i = 0;
	if (s[i] == 0)
		return (0);
	if (pos == 1)
	{
		while (s[i] && checkchar(s[i], set) == 1)
			i++;
	}
	else if (pos == 2)
	{
		while (s[i])
			i++;
		i--;
		while (s[i] && i > 0 && checkchar(s[i], set) == 1)
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;
	size_t	start_pos;
	size_t	end_pos;
	char	*ts;

	i = 0;
	if (!s1)
		return (NULL);
	count = ccount(s1, set) + 1;
	ts = (char *)malloc(sizeof(char) * count);
	if (ts == NULL)
		return (NULL);
	start_pos = position(s1, set, 1);
	end_pos = position(s1, set, 2);
	while (start_pos <= end_pos && end_pos > 0)
	{
		ts[i] = s1[start_pos];
		i++;
		start_pos++;
	}
	ts[i] = 0;
	return (ts);
}
