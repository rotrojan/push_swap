/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 03:53:09 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/22 15:08:35 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# define NB_CONVERSIONS 9
# define STR_CONVERSION "cspdiuxX%"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/*
** The t_printf structure will be declared once per execution of ft_printf.
** It will be passed throughout the functions and holds all the major
** informations needed to perform the output and return the proper value:
** - pf.fmt             : a pointer to the format string;
** - pf.buf             : the ft_printf buffer;
** - pf.i_fmt           : the index of the format string;
** - pf.i_buf           : the index of the ft_printf buffer;
** - pf.already_written : the number of already_written (when the pf.buf is
**                        fullfilled and printed, see the ft_printf_utils.c file
**                        for more informations).
*/

typedef struct s_printf
{
	char		*fmt;
	char		buf[BUFFER_SIZE];
	int			i_fmt;
	int			i_buf;
	int			already_written;
}				t_printf;

/*
** A t_spec structure will be declared everytime a '%' conversion flag is
** encountered. It holds all the conversion specifications :
** - spec.width     : minimum field width (0 by default);
** - spec.precision : required precision (-1 if not specified);
** - spec.padding   : RIGHT_PADDING by default, ZERO_PADDING if the '0' flag is
**                    encountered, LEFT_PADDING if the '-' flag is encoutered (
**                    see the enum below;
** _ spec.conv      : the conversion to perform ('c', 's', 'p', 'd', 'i', 'u',
**                    'x', 'X' or '%').
*/

typedef struct s_spec
{
	int		width;
	int		precision;
	int		padding;
	char	conv;
}				t_spec;

enum	e_padding
{
	RIGHT_PADDING,
	ZERO_PADDING,
	LEFT_PADDING
};

/*
**************************FT_PRINTF FUNCTIONS***********************************
*/

int				ft_printf(char const *format, ...);
int				ft_dprintf(int fd, char const *format, ...);
int				ft_vdprintf(int fd, char const *format, va_list args);
void			conversion(t_printf *pf, va_list args);
int				parsing(t_printf *pf, t_spec *spec, va_list args, int *conv);
void			init_spec(t_spec *spec);

/*
*************************CONVERSION FUNCTIONS***********************************
*/

void			convert_char(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_str(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_ptr(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_int(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_uint(t_printf *pf, t_spec *conv_spec, va_list args);
void			convert_hexa(t_printf *pf, t_spec *conv_spec, va_list args);

/*
******************************UTILS FUNCTIONS***********************************
*/

int				get_len_digit(unsigned long int d, int base, t_spec *spec);
void			print_buff_and_clear(t_printf *pf);
void			put_nbr_buffer(int nb, t_printf *pf, t_spec *spec);
int				ft_atoi_lite(char const *str);
void			put_hexa_buffer(
					uintmax_t nb, t_printf *pf, t_spec *spec, char base[16]);
void			write_in_buff_and_increment(
					t_printf *pf, t_spec *spec, unsigned char c);

#endif
