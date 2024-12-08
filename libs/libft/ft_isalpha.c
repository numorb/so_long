/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:36 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:01:05 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	c;

	c = 'X';
	printf("%d", ft_isalpha(c));
	printf("_%d", isalpha(c));
	return (0);
}*/
