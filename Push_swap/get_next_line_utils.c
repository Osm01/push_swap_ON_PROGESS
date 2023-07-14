/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:22:51 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/14 19:17:10 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i ++;
	}
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strdupp(char *s1)
{
	size_t	i;
	size_t	ln;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	ln = ft_strlenn(s1);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		*(str + i) = *(char *)(s1 + i);
		i ++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*join;
	unsigned int	i;
	unsigned int	index;

	i = 0;
	index = 0;
	if (!s1)
		s1 = ft_strdupp("");
	join = malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[index])
		*(join + i++) = *(s1 + index++);
	index = 0;
	while (s2[index])
		*(join + i++) = *(s2 + index++);
	*(join + i) = '\0';
	free (s1);
	return (join);
}
