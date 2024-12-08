/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:39:15 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:39:43 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	pos = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[pos] && (size_t)pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i]
				&& (size_t)(pos + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[pos]);
		}
		pos++;
	}
	return (0);
}

/*int	main(void)
{
	char	haystack[] = "intentando continuar";
	char	needle[] = "conti";
	int	n;

	n = 20;
	printf("%s", ft_strnstr(haystack, needle, n));
	printf("__%s", strnstr(haystack, needle, n));
	return (0);
}*/