/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:32:00 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 17:03:18 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Frees a texture pointer
 */
void	free_texture_pointer(t_texture *to_free)
{
	free(to_free->texture);
	free(to_free->texture_data);
	free(to_free);
}

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
	{
		free_texture_pointer(cub->tex_no);
		free(cub->no);
		free(cub->img_no);
	}
	if (cub->so != NULL)
	{
		free_texture_pointer(cub->tex_so);
		free(cub->so);
		free(cub->img_so);
	}
	if (cub->we != NULL)
	{
		free_texture_pointer(cub->tex_we);
		free(cub->we);
		free(cub->img_we);
	}
	if (cub->ea != NULL)
	{
		free_texture_pointer(cub->tex_ea);
		free(cub->ea);
		free(cub->img_ea);
	}
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
