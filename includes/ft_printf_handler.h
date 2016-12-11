/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:58:20 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/11 12:20:26 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HANDLER_H
# define FT_PRINTF_HANDLER_H
#include "ft_printf.h"

typedef int		(*t_func)(t_arg*, va_list*);

typedef struct	s_handler
{
	char	conv;
	t_func	f;
}				t_handler;

t_handler		g_table[] =
{
	{'i', &ft_printf_signed_decimal},
	{'d', &ft_printf_signed_decimal},
	{'o', &ft_printf_unsigned_base},
	{'u', &ft_printf_unsigned_base},
	{'x', &ft_printf_unsigned_base},
	{'X', &ft_printf_unsigned_base},
	{'p', &ft_printf_pointer},
	{'s', &ft_printf_string},
	{0, 0}
};

#endif
