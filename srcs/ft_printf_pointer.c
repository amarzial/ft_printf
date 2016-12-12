/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:43 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/12 15:23:29 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

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

int				ft_printf_pointer(t_arg *arg, va_list *lst)
{
	void		*num;
	char		*out;
	int			len;

	num = va_arg(*lst, void*);
	arg->flag_alt = 1;
	arg->conversion = 'x';
	if (arg->flag_left)
		arg->flag_zero = 0;
	out = ft_printf_unsignedtostr_base((intmax_t)num, arg, "0123456789abcdef");
	len = ft_strlen(out);
	padding(out, arg, len);
return (len);
}
