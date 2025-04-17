/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:35:05 by sbouaa            #+#    #+#             */
/*   Updated: 2025/04/07 00:47:44 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(void)
{
	ft_putstr_fd("Invalide Map\n", 2);
	exit(1);
}

static void	*ft_memcpy(void	*dst, const void	*src, int n)
{
	int				i;
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src)
		return (dst);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char	*s1)
{
	int		i;
	char	*p;

	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, s1_len);
	i = 0;
	while (s2[i] != '\0')
	{
		p[s1_len + i] = s2[i];
		i++;
	}
	p[s1_len + s2_len] = '\0';
	return (p);
}
