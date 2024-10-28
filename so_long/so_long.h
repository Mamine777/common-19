/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:57:22 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/28 19:59:14 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC_KEY 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 126
# define DOWN_ARROW 125
# define TILE_SIZE 48

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "/usr/local/include/mlx.h"
# include "inc/get_next_line/get_next_line.h"
# include "inc/libft/libft.h"

typedef struct s_data
{
	char	**map;
	int		map_heit;
	int		map_widt;
	char	bush;
	char	player;
	int		player_y;
	int		player_x;
	void	*player_left;
	void	*player_right;
	void	*player_forward;
	void	*player_backword;
	char	coin;
	int		total_coin;
	int		collected_coin;
	char	exit;
	char	empty;
	void	*init;
	void	*win;
	int		win_height;
	int		win_width;
	void	*img;
	void	*img_empty;
	void	*img_bush;
	void	*img_exit;
	void	*img_coin;
	void	*img_player;
	int		widt_img;
	int		heit_img;
}	t_data;

int		checkmap(int fd);
int		map_boundry(t_data *data);
void	move_player(t_data *data);
int		ft_action(int keycode, t_data *data);
int		count_coins(t_data *data);
void	read_map(t_data *data);
void	place_empty(t_data *data, int i, int j);
void	load_img(t_data *data);
int		check_angles(int fd, char *file);
void	count_dimensions(int fd, t_data *data, char *file);
void	locate_memory(t_data *data);
void	fill_map(int fd, t_data *data, char *file);
void	init_map(int fd, t_data *data, char *file);
void	so_long(int fd, t_data *data, char *file);
void	delocate(t_data *data);
void	destroy_img(t_data *data);
void	destroy_all(t_data *data);

#endif
