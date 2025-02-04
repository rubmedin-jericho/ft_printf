NAME = libftprintf.a
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
LIBFT = libft/libft.a
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: LIBFT $(NAME)

LIBFT:
	@make -C libft

%.o: %.c $(HEADER) Makefile 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER) $(LIBFT)
	$(AR) $(NAME) $(LIBFT) $(OBJS)  

clean:
	@make clean -C libft
	rm -rf $(OBJS)	

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
