/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:28:40 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 14:58:45 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_textures(t_win *window)
{
	get_map_image(window);
	get_player_image(window);
}

static void	set_win_values(t_win *window, t_map *map, t_play *player)
{
	window->map = map;
	window->height = window->map->h * 64;
	window->weight = window->map->w * 64;
	window->player = player;
	window->mlx = mlx_init();
	if (!window->mlx)
		exit_with_error_win("Mlx cannot be initialized", window);
	window->win = mlx_new_window(window->mlx, window->weight, \
		window->height, "Just Chillin");
	if (!window->win)
		exit_with_error_win("Window cannot be opened", window);
}

t_win	*init_window(t_map *map, t_play *player)
{
	t_win	*window;

	window = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!window)
		exit_with_error_player_map("Window cannot be allocated", map, player);
	set_win_values(window, map, player);
	valid_path(window);
	get_textures(window);
	return (window);
}
