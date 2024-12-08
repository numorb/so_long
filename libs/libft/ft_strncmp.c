/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:38:31 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:38:41 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

/*int main(void)
{ 
    char    s1[] = "La casa no se cae";
    char    s2[] = "La casa se cae";
    int n;

    n = 9;
    printf("%i", ft_strncmp(s1, s2, n));
    printf("__%i", strncmp(s1, s2, n));
    return (0);
}*/