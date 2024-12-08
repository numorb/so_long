/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:33 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:42:33 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned long x, int upcase, int fd)
{
	char	*str;

	if (upcase)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (x >= 16)
		ft_puthex_fd(x / 16, upcase, fd);
	ft_putchar_fd(str[x % 16], fd);
}
