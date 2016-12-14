/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:52:38 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/14 12:43:39 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

void	ft_printf_putnchar(char c, int times)
{
	while (times--)
		write(1, &c, 1);
}

int		signeddigits(intmax_t n)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

int		unsigneddigits(uintmax_t n)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}
