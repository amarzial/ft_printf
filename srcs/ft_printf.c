#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"



static int		print_arg(char **str, va_list *lst)
{
	t_arg	arg;
	int		len;

	ft_bzero(&arg, sizeof(t_arg));
	len = ft_printf_parse_arg(*str, &arg);
	return (len);
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
			print_arg(&cursor, &lst);
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
