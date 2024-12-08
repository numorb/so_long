/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:32:33 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:59:23 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dest || n == 0)
		return (dest);
	if (src > dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		}
	}
	return (dest);
}

/*int main(void)
{
	char src[10]="abcdefghij";
	char dest[10]="1234567890";

	ft_memmove(dest, src + 5, 5);
	printf("%s", dest);
	memmove(dest, src + 5, 5);
	printf("__%s", dest);
	return (0);
}*/
