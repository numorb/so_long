/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:36:34 by blnunez-          #+#    #+#             */
/*   Updated: 2024/09/14 07:56:17 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rest_of_line(char *whatever_line)
{
	char	*remainder;
	char	*end;

	remainder = ft_strchr(whatever_line, '\n');
	if (remainder)
	{
		remainder++;
		end = remainder;
		while (*end != '\0')
			end++;
		while (*remainder)
		{
			*whatever_line = *remainder;
			whatever_line++;
			remainder++;
		}
		*whatever_line = '\0';
	}
	else
	{
		whatever_line[0] = '\0';
	}
}
