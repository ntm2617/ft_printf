/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:22:44 by marvin            #+#    #+#             */
/*   Updated: 2025/09/26 19:22:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char	c, va_list	*ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*ap, unsigned char));
	else if (c == 's')
		count += ft_putstr(va_arg(*ap, const char *));
	else if (c == 'p')
		count += ft_p(va_arg(*ap, void *));;
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(*ap, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_x(va_arg(*ap, unsigned int));
	else if (c == 'X')
		count += ft_putnbr_X(va_arg(*ap, unsigned int));
	else if (c == '%')
		count += ft_putchar(va_arg(*ap, unsigned char));
	return (count);
}

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while(*format != '\0')
	{
		if (*format == '%')
			count += check(*(++format), &ap);
		else 
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
