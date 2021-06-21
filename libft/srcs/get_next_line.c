/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:23:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 23:31:04 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_append_char(char *str, char c)
{
	int		i;
	char	*str_new;

	i = 0;
	str_new = NULL;
	str_new = malloc(sizeof(*str_new) * (ft_strlen(str) + 2));
	if (str_new == NULL)
		return (NULL);
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = c;
	str_new[i + 1] = '\0';
	free(str);
	return (str_new);
}

static void	set_start(char *c, int *ret, char **str)
{
	*c = '\0';
	*ret = 1;
	*str = NULL;
	*str = malloc(sizeof(*str) * 1);
}

static int	gnl_return(int ret)
{
	if (ret == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	c;
	int		ret;
	char	*str;

	set_start(&c, &ret, &str);
	if (str == NULL)
		return (-1);
	str[0] = '\0';
	while (c != '\n' && ret != 0)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
		{
			free(str);
			return (-1);
		}
		else if (c != '\n' && ret != 0)
		{
			str = ft_append_char(str, c);
			if (str == NULL)
				return (-1);
		}
	}
	*line = str;
	return (gnl_return(ret));
}
