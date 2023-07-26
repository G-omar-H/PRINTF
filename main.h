#ifndef MAIN_H
# define MAIN_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 1024
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

int     rot13(char *str);
int     print_rev(char *s);
int     decimal_to_octal(unsigned int num);
int		_putstr(const char *str);
int		_putchar(char c);
int		count_numb(long int n);
int     print_bits(unsigned int numb);
int		phex(unsigned long n, char *arr);
int		xhex(unsigned int n, char *arr);
int     _printf(const char *format, ...);
int		putnbr(int n);
int		putnbru(unsigned int n);
void	pxx(unsigned long int n, char *arr);
int		count_numb_hex(unsigned long int n);
int     s_to_hex(char *str);
int		char_to_hex(char c);
int     check_format(va_list input, const char c);
int     count_m(const char *format);
#endif
