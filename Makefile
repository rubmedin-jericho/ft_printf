NAME = libftprintf.a
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
LIBFT_A = libft.a
SRCS = ft_printf.c \
	   ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

all: LIBFT $(NAME) 

LIBFT:
	@make -C libft

%.o: %.c $(HEADER) Makefile 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER) 
	$(AR) $(NAME) $(OBJS)  

c:
	cd libft && cp libft.a ..

clean:
	@make clean -C libft
	rm -rf $(OBJS)	

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re c
