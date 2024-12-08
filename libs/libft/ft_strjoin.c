/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:35:35 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:54:16 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*p;
	char		*start;
	const char	*tmp1;
	const char	*tmp2;

	if (!s1 || !s2)
		return (NULL);
	tmp1 = s1;
	tmp2 = s2;
	while (*tmp1++)
		;
	while (*tmp2++)
		;
	p = (char *)malloc((tmp1 - s1 + tmp2 - s2 - 1) * sizeof(char));
	if (!p)
		return (NULL);
	start = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (start);
}
