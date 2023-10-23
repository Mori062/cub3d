/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:19:37 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 23:24:32 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_mlx_utils_addr(t_data *data);

void	mlx_utils_init(t_data *data)
{
	data->mlx_utils->mlx = mlx_init();
	data->mlx_utils->win = mlx_new_window(data->mlx_utils->mlx,
			WINDOW_WIDTH, WINDOW_WIDTH, "cub3d");
	data->mlx_utils->win_width = WINDOW_WIDTH;
	data->mlx_utils->win_height = WINDOW_HEIGHT;
	if (data->mlx_utils->mlx == NULL || data->mlx_utils->win == NULL)
	{
		err_msg(MINILIBX_ERR);
		exit(1);
	}
	print_mlx_utils_addr(data);
}

#ifdef DEBUG

static void	print_mlx_utils_addr(t_data *data)
{
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("data->mlx_utils->mlx: %p\n", data->mlx_utils->mlx);
	printf("data->mlx_utils->win: %p\n", data->mlx_utils->win);
}

#else

static void	print_mlx_utils_addr(t_data *data)
{
	(void)data;
}

#endif