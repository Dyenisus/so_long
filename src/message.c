/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:47:25 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 13:53:09 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_with_error_map(const char *msg, t_map *map)
{
	ft_printf("Error: %s\n", msg);
	free_exit_map(map);
}

void	exit_with_error_player(const char *msg, t_play *player)
{
	ft_printf("Error: %s\n", msg);
	free_exit_player(player);
}

void	exit_with_error_player_map(const char *msg, t_map *map, t_play *player)
{
	ft_printf("Error: %s\n", msg);
	free_exit_player_map(map, player);
}

void	exit_with_error_win(const char *msg, t_win *window)
{
	ft_printf("Error: %s\n", msg);
	free_exit_win(window);
}
