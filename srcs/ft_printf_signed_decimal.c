/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:43 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/09 20:19:49 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static intmax_t	fetch_int(t_arg *arg, va_list *lst)
{
	intmax_t	var;

	var = va_arg(*lst, intmax_t);
	return ((int)var);
}

int				ft_printf_signed_decimal(t_arg *arg, va_list *lst)
{
	intmax_t	num;
	char		*out;
	int			len;

	num = fetch_int(arg, lst);
	out = ft_printf_signedtostr(num, arg);
	len = ft_strlen(out);
	if (arg->field_width > len)
		ft_printf_putnchar(' ', arg->field_width - len);
	ft_putstr(out);
	return (ft_strlen(out));
}
