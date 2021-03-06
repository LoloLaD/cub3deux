/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:14:53 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	parsing(char *arg, t_big_struct *bs)
{
	if (check_cub(arg))
		return (printf("Error\nbad map format\n"));
	parsing_struct_init(bs);
	if (full_parsing(arg, bs) > 0)
	{
		free_textures(bs);
		free_splits(bs->ms.map, number_of_split(bs->ms.map));
		return (1);
	}
	if (check_spawn_close(bs))
	{
		free_textures(bs);
		free_splits(bs->ms.map, number_of_split(bs->ms.map));
		return (printf("Error\nInvalid map\n"));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_big_struct	bs;

	bs.bmp = 0;
	if (argc == 2)
	{
		if (parsing(argv[1], &bs))
			return (1);
		window_prog(&bs);
	}
	else if (argc == 3)
	{
		if (check_save(argv[2]))
			return (printf("Wrong save arg\n"));
		bs.bmp = 1;
		if (parsing(argv[1], &bs))
			return (1);
		window_prog(&bs);
	}
	else
		printf("Error\nWrong arguments\n");
}
