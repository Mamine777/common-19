/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:43:39 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/26 18:19:55 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_character(char c)
{
	if (c != 'P' && c != '1' && c != 'C' && c != '0' && c != 'E')
	{
		printf("woopwoop🤡, found undefined characters, fix the map please..\n");
		return (1);
	}
	return (0);
}

int	checkmap(int fd)
{
	char	*buffer;
	int		index;

	buffer = get_next_line(fd);
	if (!buffer)
		return (0);
	while (buffer != NULL)
	{
		index = 0;
		while (buffer[index] && buffer[index] != '\n')
		{
			if (check_character(buffer[index]) == 1)
			{
				free(buffer);
				return (1);
			}
			index++;
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	int		fd;
// 	fd = open(av[1], O_RDONLY);
// 	printf("%d", checkmap(fd));	
// }