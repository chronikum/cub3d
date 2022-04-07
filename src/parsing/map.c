/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:51:46 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/07 16:29:37 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_wall_before(t_cub *cub, double x, double y)
{
	t_map	*tmp;

	tmp = cub->map;
	while (tmp)
	{
		if ((tmp->y == y - 1) && (tmp->x == x + 1))
		{
			if (tmp->o != '1')
				return (1);
			while (tmp->next && tmp->y == tmp->next->y)
			{
				if (tmp->next->o != '1')
					return (1);
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

/*	Check the object content of each node
*	node->o should either be 0/1/N/S/E/W
*	with only one occurence of N or S or E or W
*	(player and his spwaning orientation)
*/

static int	check_map_walls(t_cub *cub, t_map *node)
{
	if ((node->y == 0 && node->o != '1'))
		return (1);
	if (node->y == (cub->i - 1) && node->o != '1')
		return (1);
	if (node->x == 0 && node->o != '1')
		return (1);
	if (node->next != NULL && node->y != node->next->y && node->o != '1')
		return (1);
	return (0);
}

/*
	Checks if the map only consists of 1 and 0.
	Also, we check for exactly one player position. (NSEW)
	If no player is found, it returns false too.
	Check if the map is surrounded by Walls, if not return false
*/

bool	is_map_valid(t_cub *cub, bool player_set, int n_col)
{
	t_map	*node;

	node = cub->map;
	while (node)
	{
		if (ft_single_inset(node->o, "01NSEW") == -1)
			return (false);
		if (ft_single_inset(node->o, "NSEW") != -1)
		{
			if (player_set)
				return (false);
			player_set = true;
		}
		if (node->next != NULL && node->y != node->next->y)
			n_col = node->x;
		if (check_map_walls(cub, node))
			return (false);
		if ((node->x > n_col && node->o != '1'))
			return (false);
		if (node->next != NULL && node->y != node->next->y
			&& check_wall_before(cub, node->x, node->y))
			return (false);
		node = node->next;
	}
	return (player_set);
}

/*	Create one unique string by joing splitted array */

static char	*ft_joinstr(char **arr)
{
	char	*tmp;
	char	*buf;
	int		i;

	i = 1;
	if (arr == NULL || arr[0] == NULL)
		return (NULL);
	buf = ft_strdup(arr[0]);
	while (arr[i] != NULL)
	{
		tmp = ft_strjoin(buf, arr[i]);
		free(buf);
		buf = tmp;
		i++;
	}
	return (buf);
}

/*
	Parses single lines of the map.
	Creates the t_map and t_map_data linked lists and
	combines them.
*/
int	map(t_cub *cub, t_map *tmp, char *read, int i)
{
	static t_map_data	*map_data = NULL;
	char				**arr;
	char				*str;

	arr = ft_split(read, ' ');
	str = ft_joinstr(arr);
	if (ft_memfreeall((void **)arr) && str == NULL)
		return (1);
	if (!map_data)
		map_data = ft_data_new_data(ft_strdup(read));
	else
		ft_data_append_data(&map_data, ft_data_new_data(ft_strdup(read)));
	while (str[i] != '\0')
	{
		tmp = ft_lstnew();
		tmp->x = i;
		tmp->y = cub->i;
		tmp->o = str[i++];
		ft_lstadd_back(&cub->map, tmp);
	}
	cub->i += 1;
	cub->map_data = map_data;
	return (0);
}
