/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:20:16 by blnunez-          #+#    #+#             */
/*   Updated: 2024/06/22 18:06:18 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*int	main(void)
{
	int	c;

	c = 13;
	printf("%d",ft_isdigit(c));
	printf("_%d",isdigit(c));
	return (0);
}*/
