/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:50 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:30:05 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsigned_fd(unsigned int x, int fd)
{
	if (x >= 10)
		ft_putunsigned_fd(x / 10, fd);
	ft_putchar_fd((x % 10) + '0', fd);
}
