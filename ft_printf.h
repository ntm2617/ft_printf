/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:23:23 by marvin            #+#    #+#             */
/*   Updated: 2025/09/26 19:23:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr_X(unsigned int n);
int	ft_putnbr_x(unsigned int n);
int	ft_p(void *p);
int	check(char	c, va_list	*ap);
int	ft_printf(const char	*format, ...);

#endif