/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:59:48 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 14:43:43 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_image(t_win *window)
{
	int		w;
	int		h;

	window->player->front = mlx_xpm_file_to_image(window->mlx, \
		"./assets/front.xpm", &w, &h);
	window->player->right = mlx_xpm_file_to_image(window->mlx, \
		"./assets/right.xpm", &w, &h);
	window->player->left = mlx_xpm_file_to_image(window->mlx, \
		"./assets/left.xpm", &w, &h);
	window->player->back = mlx_xpm_file_to_image(window->mlx, \
		"./assets/back.xpm", &w, &h);
	if (!window->player->front || !window->player->right
		|| !window->player->left || !window->player->back)
		exit_with_error_win("Player image cannot be retrieved", window);
	window->player->current = window->player->front;
}

void	get_map_image(t_win *window)
{
	int		w;
	int		h;

	window->ground = mlx_xpm_file_to_image(window->mlx, \
		"./assets/ground.xpm", &w, &h);
	window->wall = mlx_xpm_file_to_image(window->mlx, \
		"./assets/wall.xpm", &w, &h);
	window->coin = mlx_xpm_file_to_image(window->mlx, \
		"./assets/chest.xpm", &w, &h);
	window->end = mlx_xpm_file_to_image(window->mlx, \
		"./assets/gate.xpm", &w, &h);
	if (!window->ground || !window->wall || !window->coin || !window->end)
		exit_with_error_win("Map image cannot be retrieved", window);
}
