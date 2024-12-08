/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:40:01 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:47:06 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			p = (char *)&s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (p);
}

/*int main()
{
    char    s[] = "Esa cosa me preocupa";
    char    *find1 = ft_strchr(s, 'a');
    char    *find2 = strchr(s, 'a');

    printf("%s", find1);
    printf("__%s", find2);
    return (0);
}*/
