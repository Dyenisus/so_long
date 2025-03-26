/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:13:34 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 14:31:01 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_exit_map(t_map *map)
{
	free_map(map);
	exit(EXIT_FAILURE);
}

void	free_exit_player(t_play *player)
{
	if (player)
		free(player);
	exit(EXIT_FAILURE);
}

void	free_exit_player_map(t_map *map, t_play *player)
{
	free_map(map);
	if (player)
		free(player);
	exit(EXIT_FAILURE);
}

void	free_exit_win(t_win *window)
{
	free_all(window);
	exit(EXIT_FAILURE);
}
