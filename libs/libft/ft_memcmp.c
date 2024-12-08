/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:27:25 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:27:31 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}

/*int main(void)
{
    char    s1[] = "casa";
    char    s2[] = "caso";
    int n = 5;

    printf("%i", ft_memcmp(s1, s2, n));
    printf("%i", memcmp (s1, s2, n));
    return (0);
}*/
