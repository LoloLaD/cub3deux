/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:30:16 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:14:39 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	a_moove(t_big_struct *bs)
{
	if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle +\
			(M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '1')
		if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle +\
			(M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '2')
			bs->ws.player_pos.y -= sin(bs->ws.p_angle + (M_PI / 2)) / 4;
	if (bs->ms.map[(int)(bs->ws.player_pos.y)]
		[(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle + (M_PI / 2)))] != '1')
		if (bs->ms.map[(int)(bs->ws.player_pos.y)]
			[(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle +\
			(M_PI / 2)))] != '2')
			bs->ws.player_pos.x += cos(bs->ws.p_angle + (M_PI / 2)) / 4;
}

void	d_moove(t_big_struct *bs)
{
	if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle +\
		(M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '1')
		if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle +\
			(M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '2')
			bs->ws.player_pos.y += sin(bs->ws.p_angle + (M_PI / 2)) / 4;
	if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x -\
		cos(bs->ws.p_angle + (M_PI / 2)))] != '1')
		if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x -\
			cos(bs->ws.p_angle + (M_PI / 2)))] != '2')
			bs->ws.player_pos.x -= cos(bs->ws.p_angle + (M_PI / 2)) / 4;
}
