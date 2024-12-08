/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:28:55 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:28:57 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		bytes;

	va_start(args, format);
	bytes = ft_printf_format(fd, format, args);
	va_end(args);
	return (bytes);
}
