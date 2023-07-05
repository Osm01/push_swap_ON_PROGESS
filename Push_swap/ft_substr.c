/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:08:02 by chdid             #+#    #+#             */
/*   Updated: 2023/06/30 17:15:40 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	ln;
	char	*str;

	i = 0;
	ln = ft_strlen(s1);
	if (!s1)
		return (0);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		*(str + i) = *(char *)(s1 + i);
		i ++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len && s[i] != '\0')
	{
		*(char *)(sub + i) = *(char *)(s + start);
		i ++;
		start ++;
	}
	*(char *)(sub + i) = '\0';
	return (sub);
}
