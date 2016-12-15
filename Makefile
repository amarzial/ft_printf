CFLAGS = -c -Wall -Werror -Wextra
SRCDIR = ./srcs/
SOURCES = ft_printf.c \
		  ft_printf_parser.c \
		  ft_printf_utils.c \
		  ft_printf_handlings.c \
		  ft_printf_signed_decimal.c \
		  ft_printf_signedtostr.c \
		  ft_printf_unsigned_base.c \
		  ft_printf_unsignedtostr_base.c \
		  ft_printf_string.c \
		  ft_printf_wstring.c \
		  ft_printf_char.c \
		  ft_printf_wchar.c \

LIBOBJS = ./libft/ft_bzero.o \
		  ./libft/ft_isascii.o \
		  ./libft/ft_isdigit.o \
		  ./libft/ft_itoa.o \
		  ./libft/ft_itoa_base.o \
		  ./libft/ft_max.o \
		  ./libft/ft_memalloc.o \
		  ./libft/ft_memset.o \
		  ./libft/ft_memcpy.o \
		  ./libft/ft_min.o \
		  ./libft/ft_putchar.o \
		  ./libft/ft_putstr.o \
		  ./libft/ft_putwchar.o \
		  ./libft/ft_putwstr.o \
		  ./libft/ft_strchr.o \
		  ./libft/ft_strnew.o \
		  ./libft/ft_abs.o \
		  ./libft/ft_atoi.o \
		  ./libft/ft_strcat.o \
		  ./libft/ft_strcpy.o \
		  ./libft/ft_strlen.o \
		  ./libft/ft_memmove.o \

NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I ./libft/includes/ -I ./includes

all: $(NAME)

$(NAME): $(OBJECTS) ./libft/libft.a
	@ echo "Creating library: $(NAME)"
	@ ar rc $(NAME) $(OBJECTS) $(LIBOBJS)
	@ ranlib $(NAME)

%.o: $(SRCDIR)%.c
	@ echo "Compiling: $<"
	@ gcc $(CFLAGS) $< $(INCLUDES)

./libft/libft.a:
	@ make -C ./libft/

clean:
	@ make -C ./libft/ clean
	@ rm -f $(OBJECTS)
	@ echo "Clean: done"

fclean: clean
	@ make -C ./libft/ fclean
	@ rm -f $(NAME)
	@ echo "Fclean: done"

re: fclean all
	@ echo "Rebuild: done"
