/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:30:05 by exam              #+#    #+#             */
/*   Updated: 2017/02/07 12:44:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

typedef struct	s_struct
{
	char		a;
	char		aa;
	char		b;
	char		bb;
	char		c;
	char		cc;
	int			x;
	int			y;
	int			z;
}				t_struct;

int				brackets(char *argv);

#endif
