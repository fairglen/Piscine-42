/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcenas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:38:25 by iferreir          #+#    #+#             */
/*   Updated: 2021/01/17 19:40:18 by iferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_line_p1(int *input, int index)
{
	return (input[index + 8]);
}

int		get_line_p2(int *input, int index)
{
	return (input[index + 12]);
}

int		get_col_p1(int *input, int index)
{
	return (input[index]);
}

int		get_col_p2(int *input, int index)
{
	return (input[index + 4]);
}

char	*get_col(char **matrix, int index)
{
	char	*col;
	int		i;

	col = (char*)malloc(sizeof(char) * 4);
	i = 0;
	while (i < 4)
	{
		col[i] = matrix[i][index];
		i++;
	}
	return (col);
}
