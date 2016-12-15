/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:49:35 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/15 12:29:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static intmax_t	fetch_int(t_arg *arg, va_list *lst)
{
	intmax_t	var;

	var = va_arg(*lst, uintmax_t);
	if (arg->conversion == 'O' || arg->conversion == 'U')
		arg->length_mod = l;
	if (arg->conversion == 'p')
		return ((uintmax_t)(void*)var);
	else if (arg->length_mod == hh)
		return ((unsigned char)var);
	else if (arg->length_mod == h)
		return ((unsigned short int)var);
	else if (arg->length_mod == l)
		return ((unsigned long int)var);
	else if (arg->length_mod == ll)
		return ((unsigned long long int)var);
	else if (arg->length_mod == j)
		return ((uintmax_t)var);
	else if (arg->length_mod == z)
		return ((size_t)var);
	return ((unsigned int)var);
}

static char		*getprefix(t_arg *arg)
{
	if (arg->flag_alt)
	{
		if (arg->conversion == 'o')
			return ("0");
		else if (arg->conversion == 'x' || arg->conversion == 'p')
			return ("0x");
		else if (arg->conversion == 'X')
			return ("0X");
	}
	return ("");
}

static void		padding(char *out, int len, t_arg *arg)
{
	int	offset;

	offset = ft_strlen(getprefix(arg));
	if (arg->flag_alt && len)
	{
		ft_memcpy(out + (arg->size - len - offset), getprefix(arg), offset);
		len += offset;
	}
	if (arg->size > len)
	{
		if (arg->flag_left)
		{
			ft_memmove(out, out + (arg->size - len), len);
			ft_memset(out + len, ' ', arg->size - len);
		}
		else if (arg->flag_zero)
		{
			ft_memset(out + offset, '0', arg->size - len - offset);
		}
		else
			ft_memset(out, ' ', arg->size - len - offset);
	}
}

static char		*getb(t_arg *arg)
{
	if (arg->conversion == 'o')
		return ("01234567");
	else if (arg->conversion == 'u')
		return ("0123456789");
	else if (arg->conversion == 'x' || arg->conversion == 'p')
		return ("0123456789abcdef");
	else if (arg->conversion == 'X')
		return ("0123456789ABCDEF");
	else
		return (0);
}

int				ft_printf_unsigned_base(t_arg *arg, va_list *lst)
{
	uintmax_t	num;
	char		*out;
	int			len;
	int			b;

	b = ft_strlen(getb(arg));
	num = fetch_int(arg, lst);
	if (arg->flag_left)
		arg->flag_zero = 0;
	len = ft_max(unsigneddigits(num, b), arg->precision);
	if (num == 0 && arg->prec_set && arg->precision == 0)
		len--;
	arg->size = ft_max(arg->field_width, len + ft_strlen(getprefix(arg)));
	out = ft_strnew(arg->size);
	ft_printf_unsignedtostr_base(out + (arg->size - len), num, arg, getb(arg));
	padding(out, len, arg);
	ft_putstr(out);
	len = ft_strlen(out);
	return (len);
}
