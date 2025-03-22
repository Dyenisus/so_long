/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:44:16 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/23 00:22:14 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	destroy_texture(t_win *window)
{
	ft_printf("Error: Could not load texture images\n");
	free_all(window);
	exit(1);
}

static void	get_textures(t_win *window)
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
		destroy_texture(window);
}

static void	set_win_values(t_win *window)
{
	window->height = window->map->h * 64;
	window->weight = window->map->w * 64;
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		ft_printf("Error: MLX initialization failed\n");
		free_all(window);
		exit(1);
	}
	window->win = mlx_new_window(window->mlx, window->weight, \
		window->height, "Just Chillin");
	if (!window->win)
	{
		ft_printf("Error: Window creation failed\n");
		free_all(window);
		exit(1);
	}
	init_player(window);
	get_textures(window);
}

void	init_win(char *arg, t_win **window)
{
	*window = (t_win *)malloc(sizeof(t_win));
	if (!(*window))
	{
		ft_printf("Error: Window initialization failed\n");
		exit(1);
	}
	(*window)->map = init_map(arg);
	set_win_values(*window);
	valid_path(*window);
}
