/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:49:26 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/10 13:42:47 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# include <stdarg.h>
# include <stdint.h>
# define FT_PRINTF_SIGNED_INTERNAL_H
# define FT_PRINTF_H
# define FT_PRINTF_FLAGS "#0- +"
# define FT_PRINTF_CONVERSION "%sSpdDioOuUxXcC"

typedef struct	s_arg
{
	int		flag_alt;
	int		flag_zero;
	int		flag_left;
	int		flag_space;
	int		flag_sign;
	int		field_width;
	int		precision;
	int		prec_set;
	enum
	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}		length_mod;
	char	conversion;
	int		size;
}				t_arg;

int				ft_printf_parse_arg(char *str, t_arg *arg);

void			ft_printf_handler(t_arg *arg, va_list *lst);

int				ft_printf_signed_decimal(t_arg *arg, va_list *lst);

char			*ft_printf_signedtostr(intmax_t num, t_arg *arg);

void			ft_printf_putnchar(char c, int times);

#endif
