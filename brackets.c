/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:21:17 by exam              #+#    #+#             */
/*   Updated: 2017/02/16 00:54:57 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int check(char *argv, int index)
{
	index = 0;
	while (argv[index] && argv[index] != '(' && argv[index] != '['
	&& argv[index] != '{' && argv[index] != ')' && argv[index] != ']'
	&& argv[index] != '}')
		index++;
	if (argv[index] == 0)
		return (1);
	return (0);
}

char get_open(char c)
{
	char open;

	open = 0;
	if (c == ')')
		open = '(';
	else if (c == ']')
		open = '[';
	else if (c == '}')
		open = '{';
	return (open);
}

int brackets(char *argv)
{
	int		index;
	int		sig;
	char	open;

	index = 0;
	sig = 1;
	while (argv[index]
	&& argv[index] != ')' && argv[index] != ']' && argv[index] != '}')
		index++;
	if (argv[index] == 0)
		sig = 0;
	open = get_open(argv[index]);
	while (index >= 0
	&& argv[index] != '(' && argv[index] != '[' && argv[index] != '{')
	{
		argv[index] = ' ';
		index--;
	}
	if ((sig == 1 && index == -1) || (index >= 0 && argv[index] != open))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (index >= 0)
		argv[index] = ' ';
	if ((sig == 0 && index == -1) || check(argv, index) == 1)
	{
		ft_putstr("OK\n");
		return (0);
	}
	else
		brackets(argv);
	return (0);
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		brackets(argv[i]);
		i++;
	}
	if (argc == 1)
		ft_putchar('\n');
	return (0);
}
