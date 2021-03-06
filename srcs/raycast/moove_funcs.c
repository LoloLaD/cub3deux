/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:57:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:14:30 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wmoove(t_big_struct *bs)
{
	if (bs->ks.w == 1)
	{
		if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle))]
		[(int)bs->ws.player_pos.x] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle))]
			[(int)bs->ws.player_pos.x] != '2')
				bs->ws.player_pos.y -= sin(bs->ws.p_angle) / 4;
		if (bs->ms.map[(int)bs->ws.player_pos.y]
			[(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle))] != '1')
			if (bs->ms.map[(int)bs->ws.player_pos.y]
				[(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle))] != '2')
				bs->ws.player_pos.x += cos(bs->ws.p_angle) / 4;
	}
}

void	smoove(t_big_struct *bs)
{
	if (bs->ks.s == 1)
	{
		if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle))]
		[(int)bs->ws.player_pos.x] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle))]
			[(int)bs->ws.player_pos.x] != '2')
				bs->ws.player_pos.y += sin(bs->ws.p_angle) / 4;
		if (bs->ms.map[(int)bs->ws.player_pos.y]
			[(int)(bs->ws.player_pos.x - cos(bs->ws.p_angle))] != '1')
			if (bs->ms.map[(int)bs->ws.player_pos.y]
				[(int)(bs->ws.player_pos.x - cos(bs->ws.p_angle))] != '2')
				bs->ws.player_pos.x -= cos(bs->ws.p_angle) / 4;
	}
}

void 	sidemooves(t_big_struct *bs)
{
	if (bs->ks.a == 1)
		a_moove(bs);
	else if (bs->ks.d == 1)
		d_moove(bs);
}

void	lookmoove(t_big_struct *bs)
{
	if (bs->ks.left == 1)
	{
		bs->ws.p_angle += M_PI / 25;
		if (bs->ws.p_angle == M_PI || bs->ws.p_angle == 0)
			bs->ws.p_angle += 0.001;
		else if (bs->ws.p_angle > 2 * M_PI)
			bs->ws.p_angle -= 2 * M_PI;
	}
	else if (bs->ks.right == 1)
	{
		bs->ws.p_angle -= M_PI / 25;
		if (bs->ws.p_angle == M_PI || bs->ws.p_angle == 0)
			bs->ws.p_angle += 0.001;
		else if (bs->ws.p_angle < 0)
			bs->ws.p_angle += 2 * M_PI;
	}
}

void	updatecoord(t_big_struct *bs)
{
	wmoove(bs);
	smoove(bs);
	sidemooves(bs);
	lookmoove(bs);
}
