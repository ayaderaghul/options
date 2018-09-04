/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 10:22:03 by exam              #+#    #+#             */
/*   Updated: 2018/09/04 22:22:26 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		input_valid(char *str)
{
	int i;

	if (str[0] != '-')
		return (2);
	else if (str[1] == 'h')
		return (0);
	else
	{
		i = 1;
		while (str[i])
		{
			if ('a' <= str[i] && str[i] <= 'z')
				++i;
			else
				return (-1);
		}
		return (1);
	}
}

int		input_type(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = input_valid(av[i]);
		if (j == -1)
		{
			write(1, "Invalid Options\n", 16);
			return (0);
		}
		if (j == 0)
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		else
			++i;
	}
	return (1);
}

void	fill_in(char *str, int *tab)
{
	int i;
	int posn;

	i = 1;
	while (str[i])
	{
		if ('y' <= str[i] && str[i] <= 'z')
			tab['z' - str[i] + 6] = '1';
		else if ('q' <= str[i] && str[i] <= 'x')
			tab['z' - str[i] + 7] = '1';
		else if ('i' <= str[i] && str[i] <= 'p')
		{
			posn = 'z' - str[i] + 8;
			tab[posn] = '1';
		}
		else if ('a' <= str[i] && str[i] <= 'h')
		{
			posn = 'z' - str[i] + 9;
			tab[posn] = '1';
		}
		++i;
	}
}

void	print_options(int ac, char **av)
{
	int tab[36];
	int i;
	int j;

	j = 0;
	while (j < 36)
	{
		if (j == 8 || j == 17 || j == 26)
			tab[j] = ' ';
		else if (j == 35)
			tab[j] = '\n';
		else
			tab[j] = '0';
		++j;
	}
	i = 1;
	while (i < ac)
	{
		if (input_valid(av[i]) == 1)
			fill_in(av[i], tab);
		++i;
	}
//	tab[35] = 0;
	j = 0;
	while (j < 36)
		write(1, &tab[j++], 1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac < 2)
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	else
	{
		i = input_type(ac, av);
		if (i == 0)
			return (0);
		else
			print_options(ac, av);
	}
	return (0);
}
