/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:45:53 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 14:34:38 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_player_location(t_map *map, t_play *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_lines[i])
	{
		j = 0;
		while (map->map_lines[i][j])
		{
			if (map->map_lines[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
}

t_play	*init_player(t_map *map)
{
	t_play	*player;

	player = (t_play *)ft_calloc(1, sizeof(t_play));
	if (!player)
	{
		free_map(map);
		exit_with_error_player("Player Cannot Be Initialized", player);
	}
	get_player_location(map, player);
	return (player);
}
