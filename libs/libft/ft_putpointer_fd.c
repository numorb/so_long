/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:40 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:44:53 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpointer_fd(void *p, int fd)
{
	if (p == NULL || p == 0)
		ft_putstr_fd("(nil)", fd);
	ft_putstr_fd("0x", fd);
	ft_puthex_fd((unsigned long)p, 0, fd);
}
