/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:47:15 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/10 01:10:18 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_data_addr(t_data *data);

t_data	*init_data(t_parser *parser)
{
	t_data	*data;

	data = (t_data *)malloc_err(sizeof(t_data));
	data->mlx_utils = (t_mlx_utils *)malloc_err(sizeof(t_mlx_utils));
	data->parser = parser;
	if (parser->player_dir == UNKNOWN)
		exit(err_msg("Unknown player direction\n"));
	data->player_dir = (double)(parser->player_dir * 90) * (M_PI / 180);
	data->player_pos_x = (double)parser->start_point_x + 0.5;
	data->player_pos_y = (double)parser->start_point_y + 0.5;
	mlx_utils_init(data);
	print_data_addr(data);
	return (data);
}

#ifdef DEBUG

static void	print_data_addr(t_data *data)
{
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("data: %p\n", data);
	printf("data->mlx_utils: %p\n", data->mlx_utils);
}

#else

static void	print_data_addr(t_data *data)
{
	(void)data;
}

#endif
