/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:47:29 by iferreir          #+#    #+#             */
/*   Updated: 2021/01/17 18:52:02 by iferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**matrix_init(void)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	matrix = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		matrix[i] = (char*)malloc(sizeof(char) * 4);
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = '0';
			j++;
		}
		i++;
	}
	return (matrix);
}

void	delete_matrix(char **matrix)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	print_matrix(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &matrix[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
