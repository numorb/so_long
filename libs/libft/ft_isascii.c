/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:28:10 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:05:18 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*int	main(void)
{
	char	c = '\n';

	printf("%d", ft_isascii(c));
	printf("_%d",isascii(c));
	return (0);
}*/
