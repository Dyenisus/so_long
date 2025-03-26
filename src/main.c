/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:55:35 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 13:21:30 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_play	*player;
	t_win	*win;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long maps/map_name.ber\n");
		exit(EXIT_FAILURE);
	}
	xmp_check();
	map_check(argv[1]);
	map = init_map(argv[1]);
	player = init_player(map);
	win = init_window(map, player);
	render_map(win);
	motion(win);
	mlx_loop(win->mlx);
	return (0);
}
