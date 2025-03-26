/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:13:20 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 13:14:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_textures(t_win *window, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(window->mlx, window->win, window->ground, x, y);
	else if (c == 'P')
	{
		window->player->x = x;
		window->player->y = y;
		mlx_put_image_to_window(window->mlx, window->win, \
			window->player->current, x, y);
	}
	else if (c == '1')
		mlx_put_image_to_window(window->mlx, window->win, window->wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(window->mlx, window->win, window->coin, x, y);
	else if (c == 'E')
	{
		window->map->gate_x = x;
		window->map->gate_y = y;
		mlx_put_image_to_window(window->mlx, window->win, window->end, x, y);
	}
}

void	render_map(t_win *window)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (window->map->map_lines[j])
	{
		i = 0;
		x = 0;
		while (window->map->map_lines[j][i])
		{
			set_textures(window, window->map->map_lines[j][i++], x, y);
			x += 64;
		}
		j++;
		y += 64;
	}
}
