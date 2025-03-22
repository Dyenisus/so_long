/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:51:34 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/22 22:35:56 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_player(t_win *window)
{
	ft_printf("Error: Could not load player images\n");
	free_all(window);
	exit(1);
}

static void	set_player_image(t_win *window, t_play *player)
{
	int		w;
	int		h;

	player->front = mlx_xpm_file_to_image(window->mlx, \
		"./assets/front.xpm", &w, &h);
	player->right = mlx_xpm_file_to_image(window->mlx, \
		"./assets/right.xpm", &w, &h);
	player->left = mlx_xpm_file_to_image(window->mlx, \
		"./assets/left.xpm", &w, &h);
	player->back = mlx_xpm_file_to_image(window->mlx, \
		"./assets/back.xpm", &w, &h);
	if (!player->front || !player->right || !player->left || !player->back)
		destroy_player(window);
	player->current = player->front;
}

static void	get_player_location(t_win *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map->map_lines[i])
	{
		j = 0;
		while (window->map->map_lines[i][j])
		{
			if (window->map->map_lines[i][j] == 'P')
			{
				window->player->x = j;
				window->player->y = i;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_win *window)
{
	t_play	*player;

	player = (t_play *)ft_calloc(1, sizeof(t_play));
	if (!player)
	{
		ft_printf("Error: Player Cannot Be Initialized\n");
		free_all(window);
		exit(1);
	}
	set_player_image(window, player);
	window->player = player;
	get_player_location(window);
}
