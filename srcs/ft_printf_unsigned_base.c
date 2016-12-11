/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:43 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/11 12:33:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static intmax_t	fetch_int(t_arg *arg, va_list *lst)
{
	intmax_t	var;

	var = va_arg(*lst, intmax_t);
	if (arg->length_mod == hh)
		return ((unsigned char) var);
	else if (arg->length_mod == h)
		return ((unsigned short int) var);
	else if (arg->length_mod == l)
		return ((unsigned long int) var);
	else if (arg->length_mod == ll)
		return ((unsigned long long int) var);
	else if (arg->length_mod == j)
		return ((uintmax_t) var);
	else if (arg->length_mod == z)
		return ((size_t) var);
	return ((unsigned int)var);
}

static void		padding(char *out, t_arg *arg, int len)
{
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putstr(out);
			ft_printf_putnchar(' ', arg->field_width - len);
		}
		else 
		{
			ft_printf_putnchar(' ', arg->field_width - len);
			ft_putstr(out);
		}
	}
	else
		ft_putstr(out);
}

int				ft_printf_unsigned_base(t_arg *arg, va_list *lst)
{
	intmax_t	num;
	char		*out;
	int			len;

	num = fetch_int(arg, lst);
	if (arg->flag_left)
		arg->flag_zero = 0;
	if (arg->conversion == 'o')
		out = ft_printf_unsignedtostr_base(num, arg, "01234567");
	else if (arg->conversion == 'u')
		out = ft_printf_unsignedtostr_base(num, arg, "0123456789");
	else if (arg->conversion == 'x')
		out = ft_printf_unsignedtostr_base(num, arg, "0123456789abcdef");
	else if (arg->conversion == 'X')
		out = ft_printf_unsignedtostr_base(num, arg, "0123456789ABCDEF");
	len = ft_strlen(out);
	padding(out, arg, len);
return (len);
}
