/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:24:00 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:00:06 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') 
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	c;

	c = 'X';
	printf("%d", ft_isalnum(c));
	printf("_%d", isalnum(c));
	return (0);
}*/
