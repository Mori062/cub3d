/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcolor_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:34:09 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 01:41:10 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	ft_split_size(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

static void	free_color_line(char **color, char *line)
{
	free(color[0]);
	free(color[1]);
	free(color[2]);
	free(color);
	free(line);
}

void	putceiling_color_to_parser(t_parser *parser, int fd)
{
	char	*line;
	char	*tmp;
	char	**color;

	line = get_next_line(fd);
	if (line == NULL)
		exit(err_msg(NO_CEILING_COLOR_ERR));
	if (ft_strncmp(line, "C ", 2) != 0)
		exit(err_msg(NO_CEILING_COLOR_ERR));
	tmp = ft_substr(line, 2, ft_strlen(line) - 3);
	free(line);
	line = tmp;
	color = ft_split(line, ',');
	if (color == NULL)
		exit(err_msg(MALLOC_ERR));
	if (ft_split_size(color) != 3)
		exit(err_msg(INVALD_CEILING_COLOR_ERR));
	if (ft_isint(color[0]) == 0 || ft_isint(color[1]) == 0
		|| ft_isint(color[2]) == 0)
		exit(err_msg(INVALD_CEILING_COLOR_ERR));
	parser->ceiling_color_r = ft_atoi(color[0]);
	parser->ceiling_color_g = ft_atoi(color[1]);
	parser->ceiling_color_b = ft_atoi(color[2]);
	free_color_line(color, line);
}
