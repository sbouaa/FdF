/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:37:26 by sbouaa            #+#    #+#             */
/*   Updated: 2025/03/23 23:57:31 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*extract_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		str = malloc(sizeof(char) * (i + 2));
	else
		str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), line = NULL, NULL);
	str = malloc(ft_strlen(line) - i + 1);
	if (!str)
		return (free(line), line = NULL, NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (free(line), line = NULL, str);
}

char	*ft_read_it(int fd, char *line)
{
	char	*buff;
	int		n_bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(line), line = NULL, NULL);
	n_bytes = 1;
	while (!ft_strchr_gnl(line) && n_bytes != 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		buff[n_bytes] = '\0';
		line = ft_strjoin_gnl(line, buff);
		if (!line)
			return (free(buff), buff = NULL, NULL);
	}
	return (free(buff), buff = NULL, line);
}

char	*gnl(int fd)
{
	static char	*line;
	char		*str;

	if (fd == -2)
		return (free(line), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (free(line), line = NULL, NULL);
	line = ft_read_it(fd, line);
	if (!line)
		return (NULL);
	str = extract_line(line);
	if (!str)
		return (free(line), line = NULL, NULL);
	line = ft_new_line(line);
	if (!line)
		return (str);
	return (str);
}
