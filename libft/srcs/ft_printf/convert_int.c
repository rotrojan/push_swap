/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:22:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 16:58:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE 10

/*
** All the conversions functions are build on the same pattern : the function
** uses va_arg to get the corresponding argument in the proper type, and then
** calls one of the two sub-functions dedicated to handle (namely) either the
** "right_padding" (with the specified padding character, '0' or ' ') or the
** "left_padding".
** Since '%i' and '%d' accept signed arguments, the function handles the
** position of the minus sign in the output.
*/

static void	left_padding(t_printf *pf, t_spec *spec, int d)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	if (d < 0)
		write_in_buff_and_increment(pf, spec, '-');
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
	if (!d && !spec->precision && spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
	else if (d || spec->precision)
		put_nbr_buffer(d, pf, spec);
	while (spec->width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void	right_padding_fill(t_printf *pf, t_spec *spec, int d, char c)
{
	int		to_write;

	to_write = get_len_digit(d, BASE, spec);
	if (c == '0' && spec->precision != -1)
		c = ' ';
	if (d < 0 && c == '0')
		write_in_buff_and_increment(pf, spec, '-');
	while ((spec->width > to_write) && (spec->width > spec->precision))
	{
		if (d < 0 && (spec->width == to_write + 1
				|| spec->width == spec->precision + 1))
			break ;
		write_in_buff_and_increment(pf, spec, c);
	}
	if (d < 0 && c == ' ')
		write_in_buff_and_increment(pf, spec, '-');
	else if (d < 0 && spec->width > to_write)
		write_in_buff_and_increment(pf, spec, '0');
	while (spec->precision > to_write)
	{
		write_in_buff_and_increment(pf, spec, '0');
		spec->precision--;
	}
}

static void	right_padding(t_printf *pf, t_spec *spec, int d, char c)
{
	right_padding_fill(pf, spec, d, c);
	if (!d && !spec->precision && spec->width)
		write_in_buff_and_increment(pf, spec, ' ');
	else if (d || spec->precision)
		put_nbr_buffer(d, pf, spec);
}

void	convert_int(t_printf *pf, t_spec *spec, va_list args)
{
	int		d;

	d = va_arg(args, int);
	if (spec->padding == LEFT_PADDING)
		left_padding(pf, spec, d);
	else if (spec->padding == ZERO_PADDING)
		right_padding(pf, spec, d, '0');
	else if (spec->padding == RIGHT_PADDING)
		right_padding(pf, spec, d, ' ');
}
