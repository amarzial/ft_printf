/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:29:21 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/05 19:28:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FT_PRINTF_FLAGS "#0- +"
# define FT_PRINTF_LEN_MOD "hljz"
# define FT_PRINTF_CONVERSION "sSpdDioOuUxXcC"

typedef struct	s_arg
{
	char	*flag;
	int		field_width;
	int		precision;
	char	*length_mod;
	char	conversion;
}				t_arg;

int				ft_printf(const char *format, ...);

#endif
