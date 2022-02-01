/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/24 13:41:53 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	leaks(void)
{
	system("leaks -q game");
}

int	main(int argc, char **argv)
{
	t_data_map	*map;
	int			check;
	char		*dir;

	atexit(leaks);
	if (argc >= 2)
		dir = ft_strjoin("./srcs/assets/", argv[1]);
	else
	{
		printf("Error no data inserted\n");
		return (0);
	}
	map = mapreader(dir);
	free(dir);
	check = mapcheck(map);
	if (check == 1)
		start_game(map);
	else
	{
		if (check == -1)
			free(map);
		else
			free_all(map);
	}
}
/*
	t_list 		**list;
	t_list 		**player;
	int i;
	
	list = map->list;
	player = map->player;
	printf("\nMapa a mostrar\n");
	i = 0;
	while (map->showmap[i] != 0)
	{
		printf("%s\n", map->showmap[i]);
		i++;
	}
	printf("\nMapa de fondo\n");
	i = 0;
	while (map->showmap[i] != 0)
	{
		printf("%s\n", map->background_map[i]);
		i++;
	}

	printf("\nObjetos en la lista\n");
	while ((*list) != 0)
	{
		printf ("Objeto tipo : %c , Array pos[%i][%i]\n", (*list)->type, (*list)->y_axis, (*list)->x_axis);
		*list = (*list)->next;
	}
	printf("\nJugadores en la lista\n");
	while ((*player) != 0)
	{
		printf ("Objeto tipo : %c , Array pos[%i][%i]\n", (*player)->type, (*player)->y_axis, (*player)->x_axis);
		*player = (*player)->next;
	}

	return (0);
	*/