CFLAGS = -c -g
SOURCES = ft_printf.c \
		  ft_printf_parser.c \
		  ft_printf_utils.c \
		  ft_printf_handlings.c \
		  ft_printf_signed_decimal.c \
		  ft_printf_signedtostr.c \
		  ft_printf_unsigned_base.c \
		  ft_printf_unsignedtostr_base.c \
		  ft_printf_pointer.c \
		  ft_printf_string.c \

all:
	rm -f libprintf.a
	gcc $(CFLAGS) $(addprefix ./srcs/, $(SOURCES)) -L ../libft/ -lft -I ../libft/includes/ -I ./includes/
	ar rc libprintf.a *.o
