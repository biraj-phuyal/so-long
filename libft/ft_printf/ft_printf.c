/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/04 16:09:11 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_char_and_str(char c, char *str, int mode)
{
	int	i;

	if (mode == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_numbers(long n, int base, char *digits, int is_unsigned)
{
	int	count;

	count = 0;
	if (!is_unsigned && n < 0)
	{
		count += ft_char_and_str('-', NULL, 0);
		if (n == -2147483648)
			return (count + ft_char_and_str(0, "2147483648", 1));
		n *= -1;
	}
	if (n >= base)
		count += ft_numbers(n / base, base, digits, 1);
	count += ft_char_and_str(digits[n % base], NULL, 0);
	return (count);
}

int	ft_hex_pointer(unsigned long long n, int initial)
{
	int	count;

	count = 0;
	if (initial && n == 0)
		return (write(1, "0x0", 3));
	if (initial)
		count += write(1, "0x", 2);
	if (n >= 16)
		count += ft_hex_pointer(n / 16, 0);
	count += ft_char_and_str("0123456789abcdef"[n % 16], NULL, 0);
	return (count);
}

int	ft_formater(va_list args, const char format)
{
	if (format == 'c')
		return (ft_char_and_str(va_arg(args, int), NULL, 0));
	else if (format == 's')
		return (ft_char_and_str(0, va_arg(args, char *), 1));
	else if (format == 'p')
		return (ft_hex_pointer(va_arg(args, unsigned long long), 1));
	else if (format == 'd' || format == 'i')
		return (ft_numbers(va_arg(args, int), 10, "0123456789", 0));
	else if (format == '%')
		return (ft_char_and_str('%', NULL, 0));
	else if (format == 'u')
		return (ft_numbers(va_arg(args, unsigned int), 10, "0123456789", 1));
	else if (format == 'x')
		return (ft_numbers(va_arg(args, unsigned int), 16,
				"0123456789abcdef", 1));
	else if (format == 'X')
		return (ft_numbers(va_arg(args, unsigned int), 16,
				"0123456789ABCDEF", 1));
	else
		return (ft_char_and_str(format, NULL, 0));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_formater(args, format[i + 1]);
			i++;
		}
		else
			length += ft_char_and_str(format[i], NULL, 0);
		i++;
	}
	va_end(args);
	return (length);
}
