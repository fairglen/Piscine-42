/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxrush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:27:15 by brmendes          #+#    #+#             */
/*   Updated: 2021/01/17 22:32:16 by brmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		validate_matrix(int *input, char **matrix);
int		get_line_p1(int *input, int index);
int		get_line_p2(int *input, int index);
int		possible_line(int p1, int p2, char **possibilities);

void	swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int		get_poss(int *input, int ind_line, char **possibilities)
{
	int	p1;
	int	p2;

	p1 = get_line_p1(input, ind_line);
	p2 = get_line_p2(input, ind_line);
	return (possible_line(p1, p2, possibilities));
}

void	delete_possibilities(char **possibilities, int n_poss)
{
	int i;

	i = 0;
	while (i < n_poss)
	{
		free(possibilities[i]);
		i++;
	}
	free(possibilities);
}

void	copy_line(char **matrix, char *line, int line_ind)
{
	int j;

	j = 0;
	while (j < 4)
	{
		matrix[line_ind][j] = line[j];
		j++;
	}
}

char	**verify_final_matrix(int *input, char **matrix)
{
	if (validate_matrix(input, matrix))
	{
		return (matrix);
	}
	else
	{
		return (NULL);
	}
}
