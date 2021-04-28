/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:47:02 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/28 11:50:49 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	line_slope(float a1, float a2, float b1, float b2)
{
	if (a1 - b1 == 0.0)
		return (NAN);
	else
		return ((a2 - b2) / (a1 - b1));
}

void	set_inter_sprite(big_struct *bs, float x, float y)
{
	bs->ss->inter_x_sprite = x;
	bs->ss->inter_y_sprite = y;
}

int	intersections_sprite(big_struct *bs)
{
	double slope_a;
	double slope_b;

	slope_a = line_slope(bs->ws->player_pos_x, bs->ws->player_pos_y, bs->ws->player_pos_x + cos(bs->rs->r_angle), bs->ws->player_pos_y - sin(bs->rs->r_angle));
	slope_b = line_slope(bs->ss->center_sprite_x, bs->ss->center_sprite_y, bs->ss->secondpoint_x, bs->ss->secondpoint_y);
	if (slope_a == slope_b || (isnan(slope_a) && isnan(slope_b)))
		return (1);
	else if (isnan(slope_a) && !isnan(slope_b))
		set_inter_sprite(bs, bs->ws->player_pos_x, (bs->ws->player_pos_x - bs->ss->center_sprite_x) * slope_b + bs->ss->center_sprite_y);
	else if (isnan(slope_b) && !isnan(slope_a))
		set_inter_sprite(bs, bs->ss->center_sprite_x, (bs->ss->center_sprite_x - bs->ws->player_pos_x) * slope_a + bs->ws->player_pos_y);
	else
		set_inter_sprite(bs, (slope_a * bs->ws->player_pos_x - slope_b * bs->ss->center_sprite_x + bs->ss->center_sprite_y - bs->ws->player_pos_y) \
	    / (slope_a - slope_b), slope_b * (bs->ss->inter_x_sprite - bs->ss->center_sprite_x) + bs->ss->center_sprite_y);
	return (0);
}

int	sprite_infos(big_struct *bs)
{
	bs->ss->center_sprite_x = bs->rs->mapx + 0.5;
	bs->ss->center_sprite_y = bs->rs->mapy + 0.5;
	bs->ss->secondpoint_x = bs->ss->center_sprite_x + cos(bs->ws->p_angle + (M_PI / 2));
	bs->ss->secondpoint_y = bs->ss->center_sprite_y - sin(bs->ws->p_angle + (M_PI / 2));
	if (intersections_sprite(bs) == 1)
		return (1);
	bs->ss->raydist_sprite = sqrt(pow(bs->ss->center_sprite_x - bs->ws->player_pos_x, 2) + pow(bs->ss->center_sprite_y - bs->ws->player_pos_y, 2));
	bs->ss->raydist_sprite *= cos(bs->ws->p_angle - bs->rs->r_angle) / 1.33;
	bs->ss->sprite_height = bs->ps->vertic_res / bs->ss->raydist_sprite;
	bs->ss->begin_sprite = bs->ps->vertic_res / 2 - bs->ss->sprite_height / 2;
	bs->ss->end_sprite = bs->ps->vertic_res / 2 + bs->ss->sprite_height / 2;
	bs->ss->sprite_onscreen_size = bs->ss->end_sprite - bs->ss->begin_sprite;
	bs->ss->mapx_sprite = bs->rs->mapx;
	bs->ss->mapy_sprite = bs->rs->mapy;
	return (0);
}

float   dist(float xa, float xb, float ya, float yb)
{
    float   res;
    res = sqrtf(powf(xa - xb, 2) + powf(ya - yb, 2));
    return (res);
}

void	put_sprite(big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int 	color;
	float distance;

	i = 0;
	distance = dist(bs->ss->center_sprite_x, bs->ss->inter_x_sprite, bs->ss->center_sprite_y, bs->ss->inter_y_sprite);
	// if ((bs->ws->player_pos_y > bs->ss->center_sprite_y && bs->ss->center_sprite_x > bs->ss->inter_x_sprite) || (bs->ws->player_pos_y < bs->ss->center_sprite_y && bs->ss->center_sprite_x < bs->ss->inter_x_sprite))
	if ((bs->ws->p_angle <= M_PI && bs->ss->center_sprite_x >= bs->ss->inter_x_sprite) || (bs->ws->p_angle > M_PI && bs->ss->center_sprite_x < bs->ss->inter_x_sprite))
		distance *= -1;
	texture_x = bs->ts->sp.width / 2 + bs->ts->sp.width * distance;
	ratio = (float)bs->ts->sp.height / bs->ss->sprite_onscreen_size;
	while (i < bs->ss->sprite_onscreen_size && j < bs->ps->vertic_res)
	{
		if (texture_x <= 63 && texture_x >= 0)
		{
			color = bs->ts->sp.buff[texture_x + (int)((float)(i) * ratio) * bs->ts->sp.height];
			if (color != 0)
				my_mlx_pixel_put(bs, x, j, color);
		}
		j++;
		i++;
	}
}