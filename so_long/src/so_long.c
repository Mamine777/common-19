/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:33:51 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/28 18:36:57 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game(t_data *data)
{
	read_map(data);
	mlx_key_hook(data->win, ft_action, data);
	mlx_loop(data->init);
}

void	so_long(int fd, t_data *data, char *file)
{
	if (checkmap(fd) == 1 || check_angles(fd, file))
	{
		printf("Error: Invalid map!\n");
		close(fd);
		exit(1);
	}
	init_map(fd, data, file);
	if (map_boundry(data))
	{
		printf("Error: Invalid map!\n");
		return ;
	}
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, data->map_widt * TILE_SIZE,
			data->map_heit * TILE_SIZE, "pokemon slayer v90");
	load_img(data);
	move_player(data);
	ft_game(data);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: file not valid\n");
		return (1);
	}
	so_long(fd, &data, av[1]);
	destroy_all(&data);
	return (0);
}
