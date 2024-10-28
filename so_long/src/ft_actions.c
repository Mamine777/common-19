/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:18:00 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/28 17:00:17 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*the function action supppose to hook keys and also is 
responsible for moving a player from a position to another 
position and also responsible for the rules of the game*/
#include "../so_long.h"

static void	player_exit(t_data *data, int y_offset, int x_offset)
{
	int	new_x;
	int	new_y;

	new_x = x_offset + data->player_x;
	new_y = y_offset + data->player_y;
	if (data->map[new_y][new_x] == 'E' &&
	data->collected_coin == data->total_coin)
	{
		printf("GONGRATS YOU WON!!!!!\n");
		exit(0);
	}
	else if (data->map[new_y][new_x] == 'E' &&
	data->collected_coin != data->total_coin)
	{
		printf("YOU NEED TO COLLECT ALL THE COINS\n");
		return ;
	}
}

static void	player_collecting(t_data *data, int y_offset, int x_offset)
{
	int	new_x;
	int	new_y;

	new_x = x_offset + data->player_x;
	new_y = y_offset + data->player_y;
	if (data->map[y_offset][x_offset] == 'C')
	{
		data->map[y_offset][x_offset] = '0';
		data->collected_coin++;
	}
}

static void	player_move(t_data *data, int y_offset, int x_offset)
{
	int	new_x;
	int	new_y;

	new_x = x_offset + data->player_x;
	new_y = y_offset + data->player_y;
	if (data->map[new_y][new_x] != '1')
	{
		player_collecting(data, new_y, new_x);
		player_exit(data, y_offset, x_offset);
		if (data->map[new_y][new_x] != 'E' ||
			data->collected_coin == data->total_coin)
		{
			data->map[data->player_y][data->player_x] = '0';
			data->player_y = new_y;
			data->player_x = new_x;
			data->map[data->player_y][data->player_x] = 'P';
		}
	}
}

static void	ft_action_p2(int keycode, t_data *data)
{
	if (keycode == UP_ARROW)
	{
		player_move(data, -1, 0);
		data->img_player = data->player_backword;
		printf("UP\n");
	}
	else if (keycode == DOWN_ARROW)
	{
		player_move(data, 1, 0);
		data->img_player = data->player_forward;
		printf("DOWN\n");
	}
	mlx_clear_window(data->init, data->win);
	read_map(data);
	mlx_string_put(data->init,
		data->win, 30, 30, 000000, "Press ESC to exit...");
}

int	ft_action(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == LEFT_ARROW)
	{
		player_move(data, 0, -1);
		data->img_player = data->player_left;
		printf("LEFT\n");
	}
	else if (keycode == RIGHT_ARROW)
	{
		player_move(data, 0, 1);
		data->img_player = data->player_right;
		printf("RIGHT\n");
	}
	ft_action_p2(keycode, data);
	return (0);
}
