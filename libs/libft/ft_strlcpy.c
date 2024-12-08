/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:01:57 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/23 20:25:09 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/*int main(void)
{
	char	src[7] = "La casa";
	char	dest[10] = "Moho";

	printf("%lu", ft_strlcpy(dest, src, 3));
	printf("_%lu", strlcpy(dest, src, 3));
	return (0);
}*/
