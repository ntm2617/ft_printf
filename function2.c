/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:10:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 16:10:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	int				count;

	a = n % 16;
	b = n / 16;
	count = 0;
	if (b > 15)
		count += ft_putnbr_x(b);
	else if (b <= 15 && b > 0)
	{
		b = "0123456789abcdef"[b];
		write(1, &b, 1);
		count++;
	}
	a = "0123456789abcdef"[a];
	write(1, &a, 1);
	count++;
	return (count);
}

int	ft_p(void *p)
{
	unsigned int		n;
	unsigned long long	new_p;
	int					count;

	if (p == NULL)
		return (ft_putstr("(nil)"));
	count = 0;
	new_p = (unsigned long long) p;
	count += ft_putstr("0x");
	count += ft_putnbr_x((unsigned int) new_p);
	return (count);
}

// int main()
// {
// 	int a = 2297;
// 	int b;

// 	// ft_p(&a);
// 	b = ft_p(&a);
// 	printf("\n%p\n", &a);
// 	printf("%d --->>> ", b);
// }