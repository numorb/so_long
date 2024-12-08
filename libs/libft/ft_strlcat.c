/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:36:42 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:36:55 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0 || size <= dst_len)
		return (src_len + size);
	i = 0;
	while (dst_len + i + 1 < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (dst[len])
		len++;
	while (src[i] && len + i + 1 < size)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len + i == size)
		return (size);
	else
	{
		dst[len + i] = '\0';
		while (src[i])
			i++;
		return (len + i);
	}
}
*/