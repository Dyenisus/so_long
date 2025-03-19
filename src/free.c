/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:22:54 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 20:00:44 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_double(char **mapped)
{
	int	i;

	if (!mapped)
		return ;
	i = 0;
	while (mapped[i])
		free(mapped[i++]);
	free(mapped);
}

static void	free_player(t_win *window)
{
	if (!window->player)
		return ;
	if (window->player->front)
		mlx_destroy_image(window->mlx, window->player->front);
	if (window->player->right)
		mlx_destroy_image(window->mlx, window->player->right);
	if (window->player->left)
		mlx_destroy_image(window->mlx, window->player->left);
	if (window->player->back)
		mlx_destroy_image(window->mlx, window->player->back);
	free(window->player);
	window->player = NULL;
}

static void	free_mlx(t_win *window)
{
	if (!window->mlx)
		return ;
	if (window->ground)
		mlx_destroy_image(window->mlx, window->ground);
	if (window->wall)
		mlx_destroy_image(window->mlx, window->wall);
	if (window->coin)
		mlx_destroy_image(window->mlx, window->coin);
	if (window->end)
		mlx_destroy_image(window->mlx, window->end);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	// mlx_destroy_display(window->mlx); for linux;
	free(window->mlx);
	window->mlx = NULL;
}

void	free_all(t_win *window)
{
	if (!window)
		return ;
	if (window->map)
	{
		if (window->map->map_lines)
			free_double(window->map->map_lines);
		free(window->map);
		window->map = NULL;
	}
	free_player(window);
	free_mlx(window);
	free(window);
}
