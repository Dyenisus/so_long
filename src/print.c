/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:31:04 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 15:58:00 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_amongus(void)
{
	ft_printf("KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n"
		"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n"
		"KKKKKKKKKKKKKOxlc;;;;;;;;;:lx0KKKKKKKKKKK\n"
		"KKKKKKKKKK0d:.              'lOKKKKKKKKKK\n"
		"KKKKKKKKOl'  ...'',,,,,,''.. 'xKKKKKKKKKK\n"
		"KKKKKKKd'  .',,;,,;;;;;;;;;,. 'kKKKKKKKKK\n"
		"KKKKKKd.    ..........',;;;;;. ,OKKKKKKKK\n"
		"KKKKk:. .',;;;;,,'.    .',;;;,..lKKKKKKKK\n"
		"KKKo..ckKNWWWWNKOOkc,..  ';,;,. ;0XKKKKKK\n"
		"KKd.;kKXXXXXXXK0O0Ol,,.  .,;;,. .;clodOKK\n"
		"KKc ;dxxkkkkkkkkkdc,',.  .,;;,'.      .oK\n"
		"KKl ..,,;;;;;:;;;,,''.   ';,;,'. .,,'..xK\n"
		"KKO:  ....'''',''...   .',;;;,'. .'',. lK\n"
		"KKK0:         .    ....,;;,;;,..  .... ;K\n"
		"KKKK: .,'........'',;;;;;;;;;'..  .... 'K\n"
		"KKKK: .;;;;;;;;;;;;;;;;;;;;;,...  .... .K\n"
		"KKK0: .;;;;;;;;;;;;;;;;;;;;,'...  .... .K\n"
		"KKK0: .,;,;;;;;;;;;;;;;;;;,'....  .... .K\n"
		"KKKK: ..,;;;;;;;;;;;;;;;;,'.....  .... .K\n"
		"KKKKl ...'',,,,;,,,,,,,,''...... ..... .K\n"
		"KKKKd..........'................ ..... :K\n"
		"KKKKk' ......................... .... .dK\n");
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
}
