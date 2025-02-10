#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(char const *s, ...);
void	ptrnbr_base(unsigned long n, int base, int *i);
void	put_nbr(unsigned int n, int *i);
void	switch_function(char c, va_list arg, int *i);
void    print_hexa_low(unsigned long n, int *i);
void    print_hexa_upper(unsigned long n, int *i);
void     ft_putchar_fd(char c, int fd, int *i);
void    ft_putnbr_fd(int n, int fd, int *i);
int		ft_isalpha(int c);
void	ft_putstr_fd(char *s, int fd, int *count);

#endif

