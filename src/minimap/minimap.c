/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:05 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 13:53:13 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 


/**
 * Draws the player in the minimap
 */
void	draw_player(t_cub *cub)
{
	int	x;
	int	y;
	int	player_eight;

	player_eight = (PLAYER_MINIMAP_SIZE / 8);
	x = cub->player->x - player_eight;
	y = cub->player->y - player_eight;
	while (y < cub->player->y + player_eight)
	{
		while (x < cub->player->x + player_eight)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				my_mlx_pixel_put(&cub->data, x, y, 17010801);
			x++;
		}
		x = cub->player->y - player_eight;
		y++;
	}
}


/**
 * Draws squares in the minimap
 */
void	draw_square(t_cub *cub, int x, int y, int size)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (tmp_y < y + size)
	{
		while (tmp_x < x + size)
		{
			if (tmp_x >= 0 && tmp_x < MINIMAP_WIDTH && tmp_y >= 0
				&& tmp_y < MINIMAP_HEIGHT)
				my_mlx_pixel_put(&cub->data, tmp_x, tmp_y, 10101099);
			tmp_x++;
		}
		tmp_y++;
		tmp_x = x;
	}
}

/**
 * Draws the floor of the minimap
 */
void	draw_floor(t_cub *cub, int x, int y, int size)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (tmp_y < y + size)
	{
		while (tmp_x < x + size)
		{
			if (tmp_x >= 0 && tmp_x < MINIMAP_WIDTH && tmp_y >= 0
				&& tmp_y < MINIMAP_HEIGHT)
				my_mlx_pixel_put(&cub->data, tmp_x, tmp_y, 15535);
			tmp_x++;
		}
		tmp_y++;
		tmp_x = x;
	}
}

/**
 * Renders the minimap
 */
void	render_minimap(t_cub *cub)
{
	t_map	*node;
	int		pos[2];
	int		old_y;

	node = cub->map;
	pos[0] = 0;
	pos[1] = 0;
	old_y = 0;
	while (node)
	{
		if (old_y != node->y)
		{
			pos[0] = 0;
			pos[1] += TILESIZE;
		}
		if (node->o == '1')
			draw_square(cub, pos[0], pos[1], TILESIZE - 1);
		if (node->o == '0')
			draw_floor(cub, pos[0], pos[1], TILESIZE - 1);
		pos[0] += TILESIZE;
		old_y = node->y;
		node = node->next;
	}
	draw_player(cub);
}
