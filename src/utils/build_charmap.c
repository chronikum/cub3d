#include "../../inc/cub3d.h"

/*
	Builds the 2d charmap from the linked list t_map_data
	Saves the result in the cub struct.
*/

void	build_2d_charmap(t_cub *cub)
{
	t_map_data	*data;
	int			count;

	data = cub->map_data;
	count = ft_lst_data_count(cub->map_data);
	cub->c_map = xmalloc((sizeof(char *) * (count + 2)));
	count = 0;
	while (data)
	{
		cub->c_map[count] = data->data;
		data = data->next;
		count++;
	}
	cub->c_map[count] = NULL;
}

/*
	Gets the wall value at the given coordinates
*/
char	get_node_value_at(t_cub *cub, int row, int column)
{
	return (cub->c_map[row][column]);
}