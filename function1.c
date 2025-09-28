/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:25:30 by marvin            #+#    #+#             */
/*   Updated: 2025/09/27 17:25:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (count);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int		a;
	int		b;
	int		count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		n = -n;
	}
	a = n % 10;
	b = n / 10;
	if (b > 9)
		count += ft_putnbr(b);
	else if (b <= 9 && b > 0)
	{
		b = b + '0';
		write(1, &b, 1);
		count++;
	}
	a = a + '0';
	write(1, &a, 1);
	count++;
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	int				count;

	count = 0;
	a = n % 10;
	b = n / 10;
	if (b > 9)
		count += ft_putnbr_u(b);
	else if (b <= 9 && b > 0)
	{
		b = b + '0';
		write(1, &b, 1);
		count++;
	}
	a = a + '0';
	write(1, &a, 1);
	count++;
	return (count);
}

int	ft_putnbr_X(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	int				count;

	a = n % 16;
	b = n / 16;
	count = 0;
	if (b > 15)
		count += ft_putnbr_X(b);
	else if (b <= 15 && b > 0)
	{
		b = "0123456789ABCDEF"[b];
		write(1, &b, 1);
		count++;
	}
	a = "0123456789ABCDEF"[a];
	write(1, &a, 1);
	count++;
	return (count);
}

// int main()
// {
// 	int n = -4294967295;
// 	int a;

// 	a = ft_putnbr_X(n);
// 	write(1, "\n", 1);
// 	ft_putnbr_X(a);
// 	printf("\n%X\n", n);
// }