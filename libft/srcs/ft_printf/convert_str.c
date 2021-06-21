/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:21:50 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 18:01:53 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** All the conversions functions are build on the same pattern : the function
** uses va_arg to get the corresponding argument in the proper type, and then
** calls one of the two sub-functions dedicated to handle (namely) either the
** "right_padding" (with the specified padding character, '0' or ' ') or the
** "left_padding".
** In case of a NULL string, the a "(null)" string is handled exactly as if
** given in argument.
*/

static void	left_padding(t_printf *pf, t_spec *spec, char *str)
{
	if (spec->precision == -1)
		while (*str)
			write_in_buff_and_increment(pf, spec, *str++);
	else
		while (*str && spec->precision-- > 0)
			write_in_buff_and_increment(pf, spec, *str++);
	while (spec->width > 0)
		write_in_buff_and_increment(pf, spec, ' ');
}

static void	right_padding(t_printf *pf, t_spec *spec, char *str, char c)
{
	int		to_be_written;

	if ((spec->precision == -1) || (ft_strlen(str) < (size_t)spec->precision))
		to_be_written = ft_strlen(str);
	else
		to_be_written = spec->precision;
	while (spec->width > to_be_written)
		write_in_buff_and_increment(pf, spec, c);
	while (to_be_written-- > 0)
		write_in_buff_and_increment(pf, spec, *str++);
}

void	convert_str(t_printf *pf, t_spec *spec, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str != NULL)
	{
		if (spec->padding == LEFT_PADDING)
			left_padding(pf, spec, str);
		else if (spec->padding == ZERO_PADDING)
			right_padding(pf, spec, str, '0');
		else if (spec->padding == RIGHT_PADDING)
			right_padding(pf, spec, str, ' ');
	}
	else
	{
		if (spec->padding == LEFT_PADDING)
			left_padding(pf, spec, "(null)");
		else if (spec->padding == ZERO_PADDING)
			right_padding(pf, spec, "(null)", '0');
		else if (spec->padding == RIGHT_PADDING)
			right_padding(pf, spec, "(null)", ' ');
	}
}
