/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:16:09 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:32:01 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src && n)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*'If' necessary in case dest and src are null pointers so if n is
different from 0 the function doesn't attempt to access null pointers.

int	main(void)
{
	char src1[] = "Empezamos otra vez";
	char dest1[] = "A ver si terminamos";
	
	char src2[] = "Empezamos otra vez";
	char dest2[] = "A ver si terminamos";

	ft_memcpy(dest1, src1, 5);
	printf("%s", dest1);
	memcpy(dest2, src2, 5);
	printf("_%s", dest2);
	return (0);
}*/
