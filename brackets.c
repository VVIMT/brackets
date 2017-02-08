/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:36:35 by exam              #+#    #+#             */
/*   Updated: 2017/02/08 23:37:58 by vinvimo          ###   ########.fr       */
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

void	brackets_bis(char *argv, t_struct *v, int index)
{
	if (argv[index] == '(' || argv[index] == '[' || argv[index] == '{')
	{
		if (v->a == 0)
		{
			v->a = argv[index];
			v->aa = get_closing(v->a);
		}
		else if (v->a != 0 && v->b == 0 && argv[index] != v->a)
		{
			v->b = argv[index];
			v->bb = get_closing(v->b);
		}
		else if (v->a != 0 && v->b != 0 && v->c == 0
			&& argv[index] != v->a && argv[index] != v->b)
		{
			v->c = argv[index];
			v->cc = get_closing(v->c);
		}
	}
}

int		brackets(char *argv)
{
	int			index;
	t_struct	v;

	index = 0;
	reset_abc(&v);
	while (argv[index])
	{
		brackets_bis(argv, &v, index);
		if (argv[index] == v.a)
			v.x++;
		if (argv[index] == v.aa)
			v.x--;
		else if (v.x < v.y || v.x < v.z)
		{
			ft_putstr("Error1\n");
			return (0);
		}
		if (argv[index] == v.b)
			v.y++;
		if (argv[index] == v.bb)
			v.y--;
		else if (v.y < v.z)
		{
			ft_putstr("Error2\n");
			return (0);
		}
		if (argv[index] == v.c)
			v.z++;
		if (argv[index] == v.cc)
			v.z--;
		if (v.x < 0 || v.y < 0 || v.z < 0)
		{
			ft_putstr("Error3\n");
			return (0);
		}
		if (v.y == 0)
			reset_bc(&v);
		if (v.x == 0)
			reset_abc(&v);
printf("argv[index] = %c\n", argv[index]);
printf("v.a = %c v.b = %c v.c = %c\nv.aa = %c v.bb = %c v.cc == %c\nv.x = %d v.y = %d v.z = %d\n", v.a, v.b, v.c, v.aa, v.bb, v.cc, v.x, v.y, v.z);
		index++;
	}
	if (v.x == 0 && v.y == 0 && v.z == 0)
		ft_putstr("OK\n");
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
