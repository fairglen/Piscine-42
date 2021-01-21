/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvences <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:10:55 by jvences           #+#    #+#             */
/*   Updated: 2021/01/21 16:01:46 by jvences          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar (char c)
{
    write (1, &c, sizeof(c));
}

void	top(int x, int y, int w, int l)
{
	while (w <= x)
	{
		if (w == 1)
		{
			ft_putchar ('o');
		}
		else if ((w > 1) && (w < x))
		{
			ft_putchar ('-');
		}
		else if (w == x)
		{
			ft_putchar ('o');
			ft_putchar ('\n');
		}
		w++;
	}
	w = 1;
}
void	middle(int x, int y, int w, int l)

{
	while (w <= x)
	{
			if (w == 1) 
			{
				ft_putchar('|');
			}
			if ((w > 1) && (w < x))
			{
				ft_putchar(' ');
			}
			if (w == x)
			{
				ft_putchar('|');
				ft_putchar('\n');
			}
			w++;
	}		
	w = 1;
}

void	bottom (int x, int y, int w, int l)

{
	while (w <= x)
	{
		if(w == 1)
		{
			ft_putchar ('o');
		}
		else if ((w > 1) && (w < x))
		{
			ft_putchar ('-');
		}
		else if((w == x) && (w != 1))
		{
		   ft_putchar ('o');
		}
		w++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)

{
	int w;
	int l;
	int loop;

	w = 1;
	l = 1;
	loop = 1;

	while (loop < y)
	{
		if (loop == 1)
		{
			top(x, y, w, l);
		}
		if ((loop > 1) && (loop < y))
		{
			middle(x, y, w, l);
		}
		loop++;
	}
	bottom(x, y, w, l);
}

int main()
{
    rush(10,8);
}
