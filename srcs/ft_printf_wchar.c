/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:27:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/12 12:14:36 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(wchar_t out, t_arg *arg, int len)
{
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putwchar(out);
			ft_printf_putnchar(' ', arg->field_width - len);
		}
		else 
		{
			ft_printf_putnchar(' ', arg->field_width - len);
			ft_putwchar(out);
		}
	}
	else
		ft_putwchar(out);
}

int			ft_printf_wchar(t_arg *arg, va_list *lst)
{
	wchar_t		c;
	size_t		len;

	c = va_arg(*lst, wchar_t);
	len = 1;
	padding(c, arg, len);
	return (len);
}