/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:50:10 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:15:45 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char s1[] = "La loca";
	char s2[] = "La loca";

	ft_bzero(s1, 12);
	printf("%s", s1);
	bzero(s2, 12);
	printf("_%s", s2);
	return (0);
}*/
