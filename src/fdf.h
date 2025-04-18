/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:20:52 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/18 13:55:10 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <string.h>
# include  <limits.h>
# include <math.h> 
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif 

# define X 2560
# define Y 1440

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_data
{
	int		row;
	int		colm;
	float	zoom;
	float	height;
}		t_data;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*all;
	t_point	**map;
	t_data	data;
}	t_vars;

char	*ft_strchr_gnl(char *str);
char	*ft_strjoin_gnl(char *line, char *buff);
char	*ft_strdup_gnl(char *str);
char	*gnl(int fd);

//
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
void	ft_check_file(char	*file);
char	*ft_check_map(char	*file, t_data	*data);
int		check_line(char *line);
void	ft_putstr_fd(char	*str, int fd);
int		ft_strlen(char	*str);
int		ft_strcmp(char	*s1, char	*s2);
char	*ft_strchr(const char	*s, int c);
char	**ft_split(const char *s, char c);
void	ft_clear(char **p);
int		only_spaces(char	*str);
void	print_error(void);

t_point	**init_map(t_point	**map, t_data	data, char	*all);
void	ft_re(t_vars *vars);
int		ft_atoi(const char	*str);
void	ft_clean(t_point **map, int row);
int		ft_atoi_base(char	*str);
int		init_points(t_point	*map_row, char	*single_line, int row);

void	ft_draw_map(t_point	**map, t_data data, t_vars *vars);
int		init_win(t_vars *vars);
void	ft_terminate(t_vars *vars);
int		check_v(void);
void	center_object(t_point **map, t_data data);
void	isometric(t_point **map, t_data data);

#endif