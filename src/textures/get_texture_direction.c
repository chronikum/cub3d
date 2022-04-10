/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:44:08 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:02:01 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Get the texture for the wanted side
 */
t_texture	*get_text_dir(t_cub *cub)
{
	if (cub->math->side == 0 && cub->math->rayDirX < 0)
		return (cub->tex_no);
	else if (cub->math->side == 0 && cub->math->rayDirX >= 0)
		return (cub->tex_so);
	if (cub->math->side == 1 && cub->math->rayDirY < 0)
		return (cub->tex_we);
	else if (cub->math->side == 1 && cub->math->rayDirY >= 0)
		return (cub->tex_ea);
	return (cub->tex_no);
}
