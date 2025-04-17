/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:20:41 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/17 11:57:24 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_win(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (ft_terminate(vars), 1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, X, Y, "FDF_42");
	if (!vars->win_ptr)
		return (ft_terminate(vars), 1);
	vars->mlx_img = mlx_new_image(vars->mlx_ptr, X, Y);
	if (!vars->mlx_img)
		return (ft_terminate(vars), 1);
	vars->img_addr = mlx_get_data_addr(vars->mlx_img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!vars->img_addr)
		return (ft_terminate(vars), 1);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, X / 2 - 50, Y / 2, 0xFFFFFF, "Loading map...");
	return (0);
}

void	ft_check_file(char	*file)
{
	int		len;
	int		fd;

	fd = open(file, O_RDONLY | __O_DIRECTORY);
	if (fd != -1)
	{
		(ft_putstr_fd("Error opening file it's a Dir \n", 2), close(fd));
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("Error opening file \n", 2), exit(1));
	close(fd);
	len = ft_strlen(file);
	if (len < 4 || ft_strcmp(file + len - 4, ".fdf") != 0)
		(ft_putstr_fd("invalid file extension. Expected .fdf\n", 2), exit(1));
}

static int	mouse_handle(t_vars	*vars)
{
	ft_terminate(vars);
	exit(0);
	return (0);
}

static int	esc_handle(int flag, t_vars	*vars)
{
	if (flag == 65307)
		(ft_terminate(vars), exit(0));
	if (flag == 65451)
	{
		vars->data.zoom += 0.1;
		ft_re(vars);
	}
	if (flag == 65453)
	{
		vars->data.zoom -= 0.1;
		ft_re(vars);
	}
	if (flag == 104)
	{
		vars->data.height += 0.1;
		ft_re(vars);
	}
	if (flag == 107)
	{
		vars->data.height -= 0.1;
		ft_re(vars);
	}
	return (0);
}

int	main(int ac, char	**av)
{
	t_point	**map;
	t_data	data;
	t_vars	vars;

	if (ac != 2 || only_spaces(av[1]))
		(ft_putstr_fd("./fdf /path/to/fdf_file\n", 2), exit(1));
	if ((X > 2560 || Y > 1440) || check_v())
		return (ft_putstr_fd("incorrect input\n", 2), 1);
	ft_check_file(av[1]);
	if (init_win(&vars))
		(ft_putstr_fd("mlx con failed\n", 2), exit(1));
	vars.all = ft_check_map(av[1], &data);
	map = NULL;
	map = init_map(map, data, vars.all);
	if (!map)
		print_error();
	vars.map = map;
	vars.data = data;
	ft_draw_map(map, data, &vars);
	mlx_hook(vars.win_ptr, 2, 1L << 0, esc_handle, &vars);
	mlx_hook(vars.win_ptr, 17, 0, mouse_handle, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
