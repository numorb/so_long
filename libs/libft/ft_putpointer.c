/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:43 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 19:54:44 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpointer(void *p)
{
	if (p == NULL || p == 0)
		ft_putstr("(nil)");
	ft_putstr("0x");
	ft_puthex((unsigned long)p, 0);
}
