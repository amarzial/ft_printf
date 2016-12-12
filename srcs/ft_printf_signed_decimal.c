/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:43 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/12 15:27:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static intmax_t	fetch_int(t_arg *arg, va_list *lst)
{
	intmax_t	var;

	var = va_arg(*lst, intmax_t);
	if (arg->conversion == 'D')
		arg->length_mod = l;
	if (arg->length_mod == hh)
		return ((char) var);
	else if (arg->length_mod == h)
		return ((short int) var);
	else if (arg->length_mod == l)
		return ((long int) var);
	else if (arg->length_mod == ll)
		return ((long long int) var);
	else if (arg->length_mod == j)
		return ((intmax_t) var);
	else if (arg->length_mod == z)
		return ((ssize_t) var);
	return ((int)var);
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
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_signed_decimal(t_arg *arg, va_list *lst)
{
	intmax_t	num;
	char		*out;
	int			len;

	num = fetch_int(arg, lst);
	if (arg->flag_left)
		arg->flag_zero = 0;
	out = ft_printf_signedtostr(num, arg);
	len = ft_strlen(out);
	padding(out, arg, len);
	return (len);
}
