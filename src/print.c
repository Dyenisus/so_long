/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:55:51 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 01:24:27 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_amongus(void)
{
	ft_printf("KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n"
		"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n"
		"KKKKKKKKKKKKKOxlc;;;;;;;;;:lx0KKKKKKKKKKKKK\n"
		"KKKKKKKKKK0d:.              'lOKKKKKKKKKKK\n"
		"KKKKKKKKOl'  ...'',,,,,,''.. 'xKKKKKKKKKK\n"
		"KKKKKKKd'  .',,;,,;;;;;;;;;,. 'kKKKKKKKKK\n"
		"KKKKKKd.    ..........',;;;;;. ,OKKKKKKKK\n"
		"KKKKk:. .',;;;;,,'.    .',;;;,..lKKKKKKKK\n"
		"KKKo..ckKNWWWWNKOOkc,..  ';,;,. ;0XKKKKKK\n"
		"KKd.;kKXXXXXXXK0O0Ol,,.  .,;;,. .;clodOKK\n"
		"KKc ;dxxkkkkkkkkkdc,',.  .,;;,'.      .oK\n"
		"KKl ..,,;;;;;:;;;,,''.   ';,;,'. .,,'..x\n"
		"KKO:  ....'''',''...   .',;;;,'. .'',. l\n"
		"KKK0:         .    ....,;;,;;,..  .... ;\n"
		"KKKK: .,'........'',;;;;;;;;;'..  .... '\n"
		"KKKK: .;;;;;;;;;;;;;;;;;;;;;,...  .... .\n"
		"KKK0: .;;;;;;;;;;;;;;;;;;;;,'...  .... .\n"
		"KKK0: .,;,;;;;;;;;;;;;;;;;,'....  .... .\n"
		"KKKK: ..,;;;;;;;;;;;;;;;;,'.....  .... .\n"
		"KKKKl ...'',,,,;,,,,,,,,''...... ..... .\n"
		"KKKKd..........'................ ..... :\n"
		"KKKKk' ......................... .... .d\n");
}

static void	print_sus(void)
{
	ft_printf("███████╗██╗   ██╗███████╗\n"
		"██╔════╝██║   ██║██╔════╝\n"
		"███████╗██║   ██║███████╗\n"
		"╚════██║██║   ██║╚════██║\n"
		"███████║╚██████╔╝███████║\n"
		"╚══════╝ ╚═════╝ ╚══════╝\n");
}

void	print_win(void)
{
	print_sus();
	print_amongus();
	print_sus();
	ft_printf("! Helal olsun moruk !\n");
}

void	exit_with_error(const char *msg, t_map *map)
{
	ft_printf("Error: %s\n", msg);
	free_double(map->map_lines);
	free(map);
	exit(1);
}

void	print_invalid(t_map *map)
{
	if (map->player_count < 1)
		exit_with_error("Not Enough Player", map);
	if (map->end_count < 1)
		exit_with_error("Not Enough Gate", map);
	if (map->coin_count < 1)
		exit_with_error("Not Enough Coin", map);
}
