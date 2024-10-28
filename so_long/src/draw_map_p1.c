/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:44:42 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/26 19:10:39 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	place_wall(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->init, data->win,
		data->img_bush, j * TILE_SIZE, i * TILE_SIZE);
}

static void	place_coin(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->init, data->win,
		data->img_coin, j * TILE_SIZE, i * TILE_SIZE);
}

void	place_player(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->init, data->win,
		data->img_player, j * TILE_SIZE, i * TILE_SIZE);
}

void	place_exit(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->init, data->win,
		data->img_exit, j * TILE_SIZE, i * TILE_SIZE);
}

/*I place the images in the right place*/
void	read_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_heit)
	{
		j = -1;
		while (++j < data->map_widt)
		{
			if (data->map[i][j] == '0')
				place_empty(data, i, j);
			else if (data->map[i][j] == '1')
				place_wall(data, i, j);
			else if (data->map[i][j] == 'C')
				place_coin(data, i, j);
			else if (data->map[i][j] == 'E')
				place_exit(data, i, j);
			else if (data->map[i][j] == 'P')
				place_player(data, i, j);
		}
	}
}
