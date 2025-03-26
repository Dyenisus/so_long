/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:16:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 15:46:06 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_side(t_win *win, char key)
{
	if (key == 'W')
		win->player->current = win->player->back;
	else if (key == 'A')
		win->player->current = win->player->left;
	else if (key == 'S')
		win->player->current = win->player->front;
	else if (key == 'D')
		win->player->current = win->player->right;
}

static void	player_move(t_win *win, char key, int x, int y)
{
	if (win->map->coin_count == 0 && win->map->map_lines[y / 64][x / 64] == 'E')
	{
		win->player->move += 1;
		ft_printf("%d\n", win->player->move);
		print_win();
		free_all(win);
		exit(EXIT_SUCCESS);
	}
	if (win->map->map_lines[y / 64][x / 64] != '1'
		&& win->map->map_lines[y / 64][x / 64] != 'E')
	{
		player_side(win, key);
		win->player->move += 1;
		if (win->map->map_lines[y / 64][x / 64] == 'C')
			win->map->coin_count -= 1;
		win->map->map_lines[win->player->y / 64][win->player->x / 64] = '0';
		win->map->map_lines[win->map->gate_y / 64][win->map->gate_x / 64] = 'E';
		win->map->map_lines[y / 64][x / 64] = 'P';
		ft_printf("%d\n", win->player->move);
	}
}

int	key_hook(int keycode, void *param)
{
	t_win	*window;

	window = (t_win *)param;
	mlx_clear_window(window->mlx, window->win);
	if (keycode == 53) // linux keycode == 65307
	{
		ft_printf("Exitting Game.....\n");
		free_all(window);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13) //linux keycode == 119
		player_move(window, 'W', window->player->x, window->player->y - 64);
	else if (keycode == 0) // linux keycode == 97
		player_move(window, 'A', window->player->x - 64, window->player->y);
	else if (keycode == 1) // linux keycode == 115
		player_move(window, 'S', window->player->x, window->player->y + 64);
	else if (keycode == 2) // linux keycode == 100
		player_move(window, 'D', window->player->x + 64, window->player->y);
	render_map(window);
	return (0);
}

static int	close_frame(t_win *window)
{
	free_all(window);
	exit(EXIT_SUCCESS);
}

void	motion(t_win *window)
{
	mlx_hook(window->win, 2, 1L << 0, &key_hook, window);
	mlx_hook(window->win, 17, 0, &close_frame, window);
}
