/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:36:35 by exam              #+#    #+#             */
/*   Updated: 2017/02/13 23:28:38 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include <unistd.h>

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

char	get_closing(char c)
{
	if (c == '(')
		c = ')';
	else if (c == '[')
		c = ']';
	else if (c == '{')
		c = '}';
	return (c);
}

void	reset_abc(t_struct *v)
{
	v->a = 0;
	v->aa = 0;
	v->b = 0;
	v->bb = 0;
	v->c = 0;
	v->cc = 0;
	v->x = 0;
	v->y = 0;
	v->z = 0;
}

void	reset_bc(t_struct *v)
{
	v->b = 0;
	v->bb = 0;
	v->c = 0;
	v->cc = 0;
	v->y = 0;
	v->z = 0;
}

int		brackets(char *argv)
{
	int			index;
	t_struct	v;

	index = 0;
	while (argv[index]
	&& (argv[index] != ')' || argv[index] != ']' || argv[index] != '}'))
		index++;
	v.a = get_closing(argv[index]);
	v.aa = argv[index];
	while (index >= 0 && argv[index] != v.a)
	{
		argv[index] = ' ';
		index--;
	}
	if (index >= 0)
		argv[index] = ' ';
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	index++;
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc >= 2)
		while (i < argc)
			brackets(argv[i++]);
	else
		ft_putchar('\n');
	return (0);
}
