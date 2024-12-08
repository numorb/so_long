/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:04:22 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:07:41 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char	s1[4];
	char	s2[4];

	ft_memset(s1, '0', 4);
	printf("%s", s1);
	memset(s2, '0', 4);
	printf("_%s", s2);
	return (0);
} */
