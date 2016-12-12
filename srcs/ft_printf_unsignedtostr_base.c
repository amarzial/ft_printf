/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:53:17 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/11 11:47:50 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static int	ndigits(intmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

static int	getlen(t_arg *arg)
{
	int		prec;

	if (!arg->prec_set && !arg->flag_zero)
		return (0);
	prec = arg->precision;
	if (arg->flag_zero && arg->prec_set)
		return (prec);
	else
		return (ft_max(prec, arg->field_width));
}

static char	*prefix(char *str, t_arg *arg)
{
	int		len;
	char	*prefix;
	char	*out;

	if (!arg->flag_alt)
		return (str);
	len = ft_strlen(str);
	if (arg->conversion == 'o')
		prefix = "0";
	else if (arg->conversion == 'x')
		prefix = "0x";
	else if (arg->conversion == 'X')
		prefix = "0X";
	else
		return (str);
	if (!(out = ft_strnew(ft_strlen(prefix) + len)))
		return (0);
	ft_strcpy(out, prefix);
	ft_strcat(out, str);
	free(str);
	return (out);
}

char		*ft_printf_unsignedtostr_base(intmax_t n, t_arg *arg, char *base)
{
	char	*out;
	int		index;
	int		size;
	int		len;
	int		b;

	b = ft_strlen(base);
	size = ndigits(n, b);
	len = ft_max(size, getlen(arg));
	if (!(out = ft_strnew(len)))
		return (0);
	index = 0;
	while (index < len - size)
		out[index++] = '0';
	if (n == 0 && !(arg->flag_alt = 0))
		out[len - 1] = '0';
	else
	{
		while (n)
		{
			out[len-- - 1] = base[ft_abs((n % b))];
			n /= b;
		}
	}
	return (prefix(out, arg));
}
