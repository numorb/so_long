/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:08 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:55:55 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fprintf(void *output_stream, const char *format, ...)
{
	va_list	args;
	int		fd;
	int		bytes;

	if (output_stream == stderr)
		fd = 2;
	else if (output_stream == stdout)
		fd = 1;
	else if (output_stream == stdin)
		fd = 0;
	else
		fd = *(int *)output_stream;
	va_start(args, format);
	bytes = ft_printf_format(fd, format, args);
	va_end(args);
	return (bytes);
}
