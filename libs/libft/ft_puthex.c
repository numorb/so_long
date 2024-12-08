/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:36 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 19:54:37 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long x, int upcase)
{
	char	*str;

	if (upcase)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (x >= 16)
		ft_puthex(x / 16, upcase);
	ft_putchar(str[x % 16]);
}
