/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:27:29 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 20:24:57 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*int main(void)
{
    char    s[] = "Repitiendo la cosa";
    char    *find1 = ft_strchr(s, '\0');
    char    *find2 = strchr(s, '\0');

    printf("%s", find1);
    printf("__%s", find2);
    return (0);
}*/
