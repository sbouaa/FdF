/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:20:41 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/17 08:50:03 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_v(void)
{
	if ((X > 2560 || Y > 1440) || (X <= 0 || Y <= 0))
		return (1);
	if (ZOOM < -1 || ZOOM > 50)
		return (1);
	if (HEIGHT_SCALE > 40 || HEIGHT_SCALE < -40)
		return (1);
	return (0);
}

static int	line_sum(char	*line)
{
	char	**p;
	int		sum;

	sum = 0;
	p = ft_split(line, 32);
	if (!p)
		return (-1);
	while (p[sum])
		sum++;
	return (ft_clear(p), sum);
}

static int	ft_check_rec(char	*line, t_data	*data)
{
	char	**p;
	int		i;
	int		check;

	p = ft_split(line, '\n');
	if (!p)
		return (1);
	check = line_sum(p[0]);
	data->colm = check;
	data->row = 1;
	i = 1;
	while (p[i])
	{
		if (line_sum(p[i]) != check || line_sum(p[i]) == -1)
			return (ft_clear(p), 1);
		i++;
		data->row++;
	}
	return (ft_clear(p), 0);
}

int	check_line(char *line)
{
	char	**p;
	int		i;
	int		j;
	char	*str;

	str = "0123456789abcdefABCDEFxX-,+ ";
	p = ft_split(line, '\n');
	if (!p)
		return (1);
	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (!ft_strchr(str, p[i][j]))
				return (ft_clear(p), 1);
			j++;
		}
		i++;
	}
	ft_clear(p);
	return (0);
}

char	*ft_check_map(char	*file, t_data	*data)
{
	int		fd;
	char	*p;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	line = gnl(fd);
	if (!line || *line == '\n' || !*line)
		(close(fd), gnl(-2), free(line), print_error());
	p = NULL;
	while (line != NULL)
	{
		if (*line == '\n')
			(close(fd), gnl(-2), free(line), free(p), print_error());
		tmp = p;
		p = ft_strjoin(p, line);
		(free(line), free(tmp));
		line = gnl(fd);
	}
	if (!p || check_line(p) || ft_check_rec(p, data))
		(close(fd), free(p), print_error());
	data->zoom = 1;
	data->height = 1;
	return (close(fd), p);
}
