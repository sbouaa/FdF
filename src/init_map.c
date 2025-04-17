/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:04:21 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/17 12:02:05 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_re(t_vars *vars)
{
	ft_clean(vars->map, vars->data.row);
	vars->map = init_map(vars->map, vars->data, vars->all);
	memset(vars->img_addr, 0x000000, X * Y * (vars->bits_per_pixel / 8));
	ft_draw_map(vars->map, vars->data, vars);
}

void	ft_terminate(t_vars *vars)
{
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_img)
		mlx_destroy_image(vars->mlx_ptr, vars->mlx_img);
	if (vars->mlx_ptr)
		mlx_destroy_display(vars->mlx_ptr);
	ft_clean(vars->map, vars->data.row);
	free(vars->all);
	free(vars->mlx_ptr);
}

int	init_points(t_point	*map_row, char	*single_line, int row)
{
	char	**p;
	char	**z_color;
	int		i;

	p = ft_split(single_line, 32);
	if (!p)
		return (1);
	i = 0;
	while (p[i])
	{
		z_color = ft_split(p[i], ',');
		map_row[i].x = i;
		map_row[i].y = row;
		map_row[i].z = ft_atoi(p[i]);
		if (z_color[1])
			map_row[i].color = ft_atoi_base(z_color[1]);
		else
			map_row[i].color = 0xffffff;
		ft_clear(z_color);
		i++;
	}
	return (ft_clear(p), 0);
}

t_point	**init_map(t_point	**map, t_data	data, char	*all)
{
	int		i;
	char	**p;

	p = ft_split(all, '\n');
	if (!p)
		return (NULL);
	map = malloc(data.row * sizeof(t_point *));
	if (!map)
		return (free(all), ft_clear(p), NULL);
	i = 0;
	while (i < data.row)
	{
		map[i] = malloc(data.colm * sizeof(t_point));
		if (!map[i] || init_points(map[i], p[i], i))
			return (ft_clean(map, data.row), ft_clear(p), free(all), NULL);
		i++;
	}
	ft_clear(p);
	return (map);
}
