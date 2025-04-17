/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:50:10 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/17 11:55:31 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	ft_dec(int	*arr)
{
	arr[0] = INT_MAX;
	arr[1] = INT_MIN;
	arr[2] = INT_MAX;
	arr[3] = INT_MIN;
}

void	center_object(t_point **map, t_data data)
{
	int	i;
	int	j;
	int	arr[6];

	i = -1;
	ft_dec(arr);
	while (++i < data.row)
	{
		j = -1;
		while (++j < data.colm)
		{
			arr[0] = fmin(arr[0], map[i][j].x);
			arr[1] = fmax(arr[1], map[i][j].x);
			arr[2] = fmin(arr[2], map[i][j].y);
			arr[3] = fmax(arr[3], map[i][j].y);
		}
	}
	arr[4] = (X / 2) - ((arr[1] + arr[0]) / 2);
	arr[5] = (Y / 2) - ((arr[3] + arr[2]) / 2);
	i = -1;
	while (++i < data.row)
	{
		j = -1;
		while (++j < data.colm)
		{
			map[i][j].x += arr[4];
			map[i][j].y += arr[5];
		}
	}
}

void	isometric(t_point **map, t_data data)
{
	int	i;
	int	j;
	int	old_x;
	int	old_y;

	i = 0;
	while (i < data.row)
	{
		j = 0;
		while (j < data.colm)
		{
			old_x = map[i][j].x;
			old_y = map[i][j].y;
			old_x = map[i][j].x * data.zoom;
			old_y = map[i][j].y * data.zoom;
			map[i][j].x = (old_x - old_y) * cos(0.523599);
			map[i][j].y = (old_x + old_y) * sin(0.523599) - map[i][j].z
				* data.height;
			j++;
		}
		i++;
	}
	center_object(map, data);
}
