/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:40:35 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 20:47:58 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_win	*win;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map_name.ber\n");
		exit(1);
	}
	xmp_check();
	map_check(argv[1]);
	init_win(argv[1], &win);
	render_map(win);
	motion(win);
	mlx_loop(win->mlx);
	return (0);
}
