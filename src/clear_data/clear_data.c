/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:32:00 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:02:50 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Frees the map list
 */
void	free_map_lst(t_cub *cub)
{
	t_map		*to_free;
	t_map		*tmp;

	to_free = cub->map;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
}

/**
 * Free textures
 */
void	free_textures(t_cub *cub)
{
	if (cub->no != NULL)
		free(cub->no);
	if (cub->so != NULL)
		free(cub->so);
	if (cub->we != NULL)
		free(cub->we);
	if (cub->ea != NULL)
		free(cub->ea);
}

/*	Free the data related to
*	textures, colors and map
*/
int	clear_data(t_cub *cub)
{
	t_map_data	*data_tmp;
	t_map_data	*data_tofree;

	if (cub == NULL)
		return (-1);
	free_textures(cub);
	free_map_lst(cub);
	free(cub->movetrigger);
	free(cub->math);
	free(cub->player);
	data_tofree = cub->map_data;
	while (data_tofree != NULL)
	{
		data_tmp = data_tofree->next;
		free(data_tofree);
		data_tofree = data_tmp;
	}
	ft_memfreeall((void **)cub->c_map);
	free(cub);
	return (1);
}
