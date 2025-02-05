#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(char const *s, ...);
void	ptrnbr_base(unsigned long n, int base);
void	put_nbr(unsigned int n);
void	switch_function(char c, va_list arg);
void    print_hexa_low(unsigned long n);
void    print_hexa_upper(unsigned long n);

#endif
