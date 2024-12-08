/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:25:27 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:49:41 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		if (*str == (char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

/*int main(void)
{
    char s[] = "Mira la casa";
    char c = 'c';
    int n = 10;

    void *p = ft_memchr(s, c, n);
    printf("%s", (char*)p);
    void *pp = ft_memchr(s, c, n);
    printf("__%s", (char*)pp);
    return (0);
}*/
