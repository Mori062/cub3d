/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:03:47 by hhino             #+#    #+#             */
/*   Updated: 2023/11/16 19:09:28 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

typedef struct s_data		t_data;

void	draw_floor_sky(t_data *data);
void	draw_wall(t_data *data);
void	draw_minimap(t_data *data);
void	wall_image_to_window(t_data *data, int w, int h);


#endif
