/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:54:37 by mokariou          #+#    #+#             */
/*   Updated: 2024/08/05 12:00:35 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	    i++;
	return (i);
}

/*#include <stdio.h>

int main()
{
    printf("%d", ft_strlen("hello"));
}*/