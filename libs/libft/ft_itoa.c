/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:24:41 by blnunez-          #+#    #+#             */
/*   Updated: 2024/07/19 19:51:29 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int				i;
	long long		temp;

	temp = n;
	i = 1;
	if (temp < 0)
	{
		temp *= -1;
		i++;
	}
	while (temp >= 10)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

char	*ft_strrev(char *s)
{
	int				i;
	int				size;
	char			temp;

	size = ft_strlen(s);
	i = 0;
	while (i < (size / 2))
	{
		temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
		i++;
	}
	return (s);
}

void	ft_sign_handler(int n, int *neg, unsigned int *positiv)
{
	if (n < 0)
	{
		*neg = 1;
		*positiv = -n;
	}
	else
	{
		*neg = 0;
		*positiv = n;
	}
}

char	*ft_itoa(int n)
{
	int				i;
	int				neg;
	unsigned int	positiv;
	char			*p;

	i = 0;
	ft_sign_handler(n, &neg, &positiv);
	if (n == 0)
		return (ft_strdup("0"));
	p = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!p)
		return (NULL);
	ft_memset(p, '\0', (ft_intlen(n) + 1));
	while (positiv != 0)
	{
		p[i++] = (positiv % 10) + '0';
		positiv /= 10;
	}
	if (neg)
		p[i++] = '-';
	return (ft_strrev(p));
}
