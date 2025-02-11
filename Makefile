NAME = libftprintf.a
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
SRCS = ft_printf.c \
	   ft_printf_utils.c \
	   ft_putnbr_fd.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_isalpha.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER) Makefile 
	$(CC) -c $< -o $@ -g
#	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS) 

clean:
	@rm -rf $(OBJS)	

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
