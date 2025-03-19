/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:43:50 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 01:17:05 by yesoytur         ###   ########.fr       */
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
		exit(0);
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

// Left is Linux Right is Mac erase according to that
int	key_hook(int keycode, void *param)
{
	t_win	*window;

	window = (t_win *)param;
	mlx_clear_window(window->mlx, window->win);
	if (keycode == 53) // ESC keycode == 65307 || 
	{
		ft_printf("Exitting Game.....\n");
		free_all(window);
		exit(0);
	}
	else if (keycode == 13) // W keycode == 119 ||
		player_move(window, 'W', window->player->x, window->player->y - 64);
	else if (keycode == 0) // A keycode == 97 || 
		player_move(window, 'A', window->player->x - 64, window->player->y);
	else if (keycode == 1) // S keycode == 115 ||
		player_move(window, 'S', window->player->x, window->player->y + 64);
	else if (keycode == 2) // D keycode == 100 || 
		player_move(window, 'D', window->player->x + 64, window->player->y);
	render_map(window);
	return (0);
}

static int	close_frame(t_win *window)
{
	free_all(window);
	exit(0);
}

void	motion(t_win *window)
{
	// mlx_hook takes specific functions don't forget to look to prototype
	mlx_hook(window->win, 2, 1L << 0, &key_hook, window);
	mlx_hook(window->win, 17, 0, &close_frame, window);
}
