#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_printf_parse_arg(char *str, t_arg *arg)
{
	int	cnt;
	int	tmp;

	cnt = 1;
	while (ft_strchr(FT_PRINTF_FLAGS, str[cnt]))
		cnt++;
	arg->flag = ft_strsub(str, 1, cnt);
	if (ft_isdigit(str[cnt]))
		arg->field_width = ft_atoi(str + cnt);
	while (ft_isdigit(str[cnt]))
		cnt++;
	if (str[cnt] == '.')
	{
		arg->precision = ft_atoi(str + ++cnt);
		while (ft_isdigit(str[cnt]))
			cnt++;
	}
	tmp = cnt;
	while (ft_strchr(FT_PRINTF_LEN_MOD, str[cnt]))
		cnt++;
	arg->length_mod = ft_strsub(str + tmp, 0, cnt - tmp);
	if (ft_strchr(FT_PRINTF_CONVERSION, str[cnt]))
		arg->conversion = str[cnt];
	return (cnt);
}

int		ft_printf_print_arg(char **str, va_list *lst)
{
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	ft_printf_parse_arg(*str, &arg);
}

int		ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*cursor;
	int			out;

	cursor = (char*)format;
	out = 0;
	va_start(lst, format);
	while (*cursor)
	{
		if (*cursor == '%')
		{
			ft_printf_print_arg(&cursor, &lst);
		}
		else
		{
			ft_putchar(*cursor++);
			out++;
		}
	}
	va_end(lst);
	return (out);
}
