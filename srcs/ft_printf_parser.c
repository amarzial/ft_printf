/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:58:05 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/09 20:00:40 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static int	parse_len(char *str, t_arg *arg)
{
	if (*str == 'h' && *(str + 1) == 'h')
	{
		arg->length_mod = hh;
		return (2);
	}
	else if (*str == 'l' && *(str + 1) == 'l')
	{
		arg->length_mod = ll;
		return (2);
	}
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
	{
		if (*str == 'h')
			arg->length_mod = h;
		else if (*str == 'l')
			arg->length_mod = l;
		else if (*str == 'j')
			arg->length_mod = j;
		else if (*str == 'z')
			arg->length_mod = z;
		return (1);
	}
	return (0);
}

static int	parse_flag(char *str, t_arg *arg)
{
	int cnt;

	cnt = 0;
	while (ft_strchr(FT_PRINTF_FLAGS, str[cnt]))
	{
		if (str[cnt] == '#')
			arg->flag_alt = 1;
		else if (str[cnt] == '0')
			arg->flag_zero = 1;
		else if (str[cnt] == '-')
			arg->flag_left = 1;
		else if (str[cnt] == ' ')
			arg->flag_space = 1;
		else if (str[cnt] == '+')
			arg->flag_sign = 1;
		cnt++;
	}
	return (cnt);
}

int			ft_printf_parse_arg(char *str, t_arg *arg)
{
	int	cnt;

	str++;
	cnt = 0;
	cnt += parse_flag(str, arg);
	if (ft_isdigit(str[cnt]))
		arg->field_width = ft_atoi(str + cnt);
	while (ft_isdigit(str[cnt]))
		cnt++;
	if (str[cnt] == '.')
	{
		arg->prec_set = 1;
		arg->precision = ft_atoi(str + ++cnt);
		while (ft_isdigit(str[cnt]))
			cnt++;
	}
	cnt += parse_len(str + cnt, arg);
	if (ft_strchr(FT_PRINTF_CONVERSION, str[cnt]))
		arg->conversion = str[cnt];
	return (cnt + 2);
}
