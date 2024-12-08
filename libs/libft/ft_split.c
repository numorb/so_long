/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:31:54 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:53:20 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *(s + 1))
				s++;
		}
		s++;
	}
	return (i);
}

static char	*ft_fill(char const *s, char c)
{
	size_t	size;
	char	*str;
	int		i;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_backfree(char **p, int i)
{
	while (i + 1)
	{
		free(p[i]);
		i--;
	}
	free (p);
	p = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**p;

	i = 0;
	p = malloc (sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!p)
		return (NULL);
	while (*s)
	{
		if (*s != c && *s)
		{
			p[i] = ft_fill(s, c);
			if (!p[i])
			{
				ft_backfree(p, i);
				return (NULL);
			}
			i++;
			while (*s != c && *(s + 1))
				s++;
		}
		s++;
	}
	p[i] = 0;
	return (p);
}
