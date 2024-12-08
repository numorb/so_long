/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:22:39 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:50:54 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*temp;

	p = malloc(count * size);
	temp = p;
	if (p)
	{
		while (temp < (char *)p + (count * size))
		{
			*temp = 0;
			temp++;
		}
	}
	return (p);
}
