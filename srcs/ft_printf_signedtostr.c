/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:53:17 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/09 20:36:28 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static int	ndigits(int n)
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

static int	getlen(long long int num, t_arg *arg)
{
	int		prec;

	if (!arg->prec_set && !arg->flag_zero)
		return (0);
	prec = arg->precision + ((num < 0) ? 1 : 0);
	if (arg->flag_zero && arg->prec_set)
		return (prec);
	else
		return (ft_max(prec, arg->field_width));
}

char		*ft_printf_signedtostr(long long int n, t_arg *arg)
{
	char	*out;
	int		index;
	int		size;
	int		len;

	size = ndigits(n) + ((n < 0) ? 1 : 0);
	len = ft_max(size, getlen(n, arg));
	if (!(out = ft_strnew(len)))
		return (0);
	index = 0;
	if (n == 0)
		out[0] = '0';
	else
	{
		if (n < 0 && size--)
			out[index++] = '-';
		while (index < len - size)
			out[index++] = '0';
		while (n)
		{
			out[len-- - 1] = ft_abs((n % 10)) + '0';
			n /= 10;
		}
	}
	return (out);
}
