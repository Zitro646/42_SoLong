/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:20:30 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 15:08:13 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H
# include "../Libft/libft.h"
# include "../game/game.h"
# include <stdio.h>

//Enemy functions
int				check_sorroundings_y(char **show_map, int x, int y);
int				check_sorroundings_x(char **show_map, int x, int y);
int				get_new_y(char **show_map, int x, int y);
int				get_new_x(char **show_map, int x, int y);
void			enemy_patrol(t_data_map *data_map);
void			new_objective(t_data_map *data_map, int enemy_x, int enemy_y);
void			enemy_action(t_data_map *data_map);
#endif
