/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surrounded.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:54:03 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 14:59:14 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

/**
 * Checks if map is surrounded by walls
 */
bool    map_surrounded(t_cub *cub)
{
    t_map_data *data;

    data = cub->map_data;
    while (data)
    {
        if (data->data[0] != '1' || data->data[ft_strlen(data->data) - 1] != '1')
            return (false);
        data = data->next;
    }
    data = cub->map_data;
    
}