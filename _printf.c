#include "shell_header.h"
#include <stdarg.h>

/**
 * _putchar - Custom putchar function
 * @c: Character to print
 * Return: 1 (Success), -1 (Error)
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Custom puts function
 * @str: String to print
 * Return: Number of characters printed (excluding null byte)
 */
int _puts(char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        count += _putchar(*str);
        str++;
    }
    return count;
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    count += _puts(str);
                    break;
                }
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%') + _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}
