/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:01:56 by iferreir          #+#    #+#             */
/*   Updated: 2021/01/17 19:48:03 by iferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_line_p1(int *input, int index);
int		get_line_p2(int *input, int index);
int		get_col_p1(int *input, int index);
int		get_col_p2(int *input, int index);
char	*get_col(char **matrix, int index);

int		validate_p1(int p1, char *line)
{
	int		i;
	int		j;
	char	max;
	char	cont;

	i = 0;
	cont = 0;
	max = '0';
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (line[i] == line[j])
				return (0);
			j++;
		}
		if (max < line[i])
		{
			max = line[i];
			cont++;
		}
		i++;
	}
	return (cont == p1);
}

int		validate_p2(int p2, char *line)
{
	int		i;
	char	rev_max;
	int		cont;
	int		rev_cont;

	i = 3;
	rev_max = '0';
	rev_cont = 0;
	while (i >= 0)
	{
		if (rev_max < line[i])
		{
			rev_max = line[i];
			rev_cont++;
		}
		i--;
	}
	return (rev_cont == p2);
}

int		validate_col(int *input, char **matrix)
{
	int		i;
	int		p1;
	int		p2;
	char	*col;

	i = 0;
	while (i < 4)
	{
		col = get_col(matrix, i);
		p1 = get_col_p1(input, i);
		p2 = get_col_p2(input, i);
		if (validate_p1(p1, col) != 1 || validate_p2(p2, col) != 1)
		{
			free(col);
			return (0);
		}
		free(col);
		i++;
	}
	return (1);
}

int		validate_matrix(int *input, char **matrix)
{
	int		i;
	int		p1;
	int		p2;

	i = 0;
	while (i < 4)
	{
		p1 = get_line_p1(input, i);
		p2 = get_line_p2(input, i);
		if (validate_p1(p1, matrix[i]) != 1 || validate_p2(p2, matrix[i]) != 1)
		{
			return (0);
		}
		i++;
	}
	if (validate_col(input, matrix) != 1)
		return (0);
	return (1);
}
