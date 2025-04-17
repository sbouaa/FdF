/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:19:23 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/17 12:11:01 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < X && y >= 0 && y < Y)
	{
		dst = vars->img_addr + (y * vars->line_length + x
				* (vars->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	ft_set(int *arr, t_point p1, t_point p2)
{
	arr[2] = 1;
	if (p1.x > p2.x)
		arr[2] = -1;
	arr[3] = 1;
	if (p1.y > p2.y)
		arr[3] = -1;
}

static void	ft_draw_line(t_point p1, t_point p2, t_vars *vars)
{
	int	arr[4];
	int	err;
	int	e2;

	arr[0] = abs(p2.x - p1.x);
	arr[1] = abs(p2.y - p1.y);
	ft_set(arr, p1, p2);
	err = arr[0] - arr[1];
	while (1)
	{
		put_pixel(vars, p1.x, p1.y, p1.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = 2 * err;
		if (e2 > -arr[1])
		{
			err -= arr[1];
			p1.x += arr[2];
		}
		if (e2 < arr[0])
		{
			err += arr[0];
			p1.y += arr[3];
		}
	}
}

void	ft_draw_map(t_point **map, t_data data, t_vars *vars)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	isometric(map, data);
	i = -1;
	while (++i < data.row)
	{
		j = -1;
		while (++j < data.colm)
		{
			p1 = map[i][j];
			if (j + 1 < data.colm)
			{
				p2 = map[i][j + 1];
				ft_draw_line(p1, p2, vars);
			}
			if (i + 1 < data.row)
			{
				p2 = map[i + 1][j];
				ft_draw_line(p1, p2, vars);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->mlx_img, 0, 0);
}
