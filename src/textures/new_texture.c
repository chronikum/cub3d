/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:55:56 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 17:15:10 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../assets/assets.h"

/**
 * Loads a texture struct with the given img_ptr and
 * returns it
 */
t_texture	*new_texture(void *img_ptr, t_cub *cub)
{
	t_texture		*texture;

	(void) cub;
	texture = xmalloc(sizeof(t_texture)); //to free in clear_data.c
	texture->texture_ptr = mlx_get_data_addr(img_ptr, &texture->bpp, &texture->line_size,
		&texture->endian);
	texture->bpp /= 8;
	texture->width = texture->line_size / texture->bpp;
	texture->height = texture->line_size / texture->bpp;
	return (texture);
}
