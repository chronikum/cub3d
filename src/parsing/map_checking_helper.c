/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:56:14 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/13 16:58:46 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Will return true if file is at end but no map was found or
 * if the map is invalid and loaded.
 */
bool	no_or_invalid_map_in_file(t_cub *cub, int ok)
{
	if (ok == 0 && !cub->map_done && cub->id_done)
		return (true);
	return (cub->map != NULL && cub->map_done == false);
}
