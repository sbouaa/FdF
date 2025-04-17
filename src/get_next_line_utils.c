/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:38:23 by sbouaa            #+#    #+#             */
/*   Updated: 2025/03/23 22:33:49 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr_gnl(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *str)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	if (new_str[0] == '\0')
	{
		free(new_str);
		new_str = NULL;
	}
	return (new_str);
}

char	*ft_strjoin_gnl(char *line, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!buff)
		return (NULL);
	if (!line)
		return (ft_strdup_gnl(buff));
	str = malloc(ft_strlen(line) + ft_strlen(buff) + 1);
	if (!str)
		return (free(line), line = NULL, NULL);
	i = 0;
	while (line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(line), line = NULL, str);
}
