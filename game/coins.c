/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:44:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 14:26:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_coins(char **show_map)
{
	int		x;
	int		y;
	int		coins;

	coins = 0;
	y = 0;
	while (show_map[y] != 0)
	{
		x = 0;
		while (show_map[y][x] != 0)
		{
			if (show_map[y][x] == 'C')
				coins++;
			x++;
		}
		y++;
	}
	return (coins);
}
