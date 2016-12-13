/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:10:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/13 21:51:27 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		putnwstr(const wchar_t *str, size_t size)
{
	while (size--)
		ft_putwchar(*str++);
}

static void		padding(const wchar_t *out, t_arg *arg, int len)
{
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			putnwstr(out, len);
			ft_printf_putnchar(' ', arg->field_width - len);
		}
		else
		{
			ft_printf_putnchar(' ', arg->field_width - len);
			putnwstr(out, len);
		}
	}
	else
		putnwstr(out, len);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_wstring(t_arg *arg, va_list *lst)
{
	const wchar_t	*str;
	size_t			len;

	str = va_arg(*lst, wchar_t*);
	len = 0;
	while (str[len])
		len++;
	padding(str, arg, len);
	return (len);
}
