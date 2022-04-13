/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:23:08 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/13 14:18:47 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Builds 2d charmap if identifier and map are ok.
 * Otherwise, it will exit on error.
 * Returns the cub object
 */
t_cub	*build_map_if_ok(t_cub *cub)
{
	if ((cub->id_done == false || cub->map_done == false))
		exit_on_error();
	build_2d_charmap(cub);
	return (cub);
}

/*	Initialize the data and the pointers
*	NO/SO/WE/EA Identifiers
*	F Floor RGB Colours
*	C Ceiling RGB Colours
*
*/
void	init_data(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->floor = -1;
	cub->ceiling = -1;
	cub->i = 0;
	cub->map = NULL;
	cub->id_done = false;
	cub->map_done = false;
	cub->map_data = NULL;
}

/*	Create the data struct
*	Read the file
*	Verify the content
*	Store the data
*	Builds the char map used later
*/

t_cub	*get_data(int fd, char *read, t_cub *cub)
{
	int	ok;

	cub = (t_cub *)xmalloc(sizeof(t_cub));
	init_data(cub);
	ok = get_next_line(fd, &read);
	while (read != NULL)
	{
		if (ft_strcmp(read, "\0") == 0)
		{
			cub->map_done = is_map_valid(cub, false, 0);
			if ((ok == 0 && (!cub->id_done))
				|| (cub->map != NULL && cub->map_done == false))
				return (NULL);
			else if (ok == 0 && cub->map_done == true && memfree((void *)read))
				break ;
		}
		else if (cub->id_done == false && identifier(cub, read))
			exit_on_error();
		else if (cub->id_done == true && map(cub, NULL, read, 0))
			exit_on_error();
		identifier_done(cub);
		free(read);
		ok = get_next_line(fd, &read);
	}
	return (build_map_if_ok(cub));
}

/*	This function is the main parsing function, it will
*		Check if the content of the file respect the rules
*		Store the data
*/

t_cub	*check_file_content(char *file)
{
	int		fd;
	t_cub	*cub;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_on_error();
	cub = get_data(fd, NULL, NULL);
	if (cub == NULL)
		exit_on_error();
	if (close(fd) == -1)
		exit_on_error();
	return (cub);
}

/**
**	Check if the filename has
**	a valid extension (.cub)
**	If not, it returns 0.
*/
int	check_file_format(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (1);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".cub", 4) == 0)
		return (0);
	return (1);
}
