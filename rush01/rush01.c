/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:04:48 by iferreir          #+#    #+#             */
/*   Updated: 2021/01/17 22:42:20 by brmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	swap(char *x, char *y);
void	delete_matrix(char **matrix);
int		validate_p1(int p1, char *line);
int		validate_p2(int p2, char *line);
int		validate_matrix(int *input, char **matrix);
int		get_line_p1(int *input, int index);
int		get_line_p2(int *input, int index);
int		get_poss(int *input, int ind_line, char **possibilities);
void	delete_possibilities(char **possibilities, int n_poss);
void	copy_line(char **matrix, char *line, int line_ind);
char	**verify_final_matrix(int *input, char **matrix);

void	permutations(char *a, int left_ind, char **per, int *n_permutations)
{
	int i;
	int j;

	i = left_ind;
	if (left_ind == 3)
	{
		per[(*n_permutations)] = (char*)malloc(sizeof(char) * 4);
		j = 0;
		while (j < 4)
		{
			per[(*n_permutations)][j] = a[j];
			j++;
		}
		(*n_permutations)++;
	}
	else
	{
		while (i <= 3)
		{
			swap((a + left_ind), (a + i));
			permutations(a, left_ind + 1, per, n_permutations);
			swap((a + left_ind), (a + i));
			i++;
		}
	}
}

int		add_poss_line(int p1, int p2, char **perm, char **possibilities)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < 24)
	{
		if (validate_p1(p1, perm[i]) == 1 && validate_p2(p2, perm[i]) == 1)
		{
			possibilities[j] = (char*)malloc(sizeof(char) * 4);
			k = 0;
			while (k < 4)
			{
				possibilities[j][k] = perm[i][k];
				k++;
			}
			j++;
		}
		free(perm[i]);
		i++;
	}
	return (j);
}

int		possible_line(int p1, int p2, char **possibilities)
{
	char	a[4];
	char	**perm;
	int		n_permutations;
	int		res;

	a[0] = '1';
	a[1] = '2';
	a[2] = '3';
	a[3] = '4';
	perm = (char**)malloc(sizeof(char*) * 24);
	n_permutations = 0;
	permutations(a, 0, perm, &n_permutations);
	res = add_poss_line(p1, p2, perm, possibilities);
	free(perm);
	return (res);
}

char	**update_matrix(int index, char **matrix, char *line)
{
	char	**new_matrix;
	int		i;

	new_matrix = (char**)malloc(sizeof(char*) * 4);
	i = 0;
	while (i < 4)
	{
		new_matrix[i] = (char*)malloc(sizeof(char) * 4);
		if (i == index)
		{
			copy_line(new_matrix, line, i);
		}
		else
		{
			copy_line(new_matrix, matrix[i], i);
		}
		i++;
	}
	return (new_matrix);
}

char	**solve_matrix(int *input, char **matrix, int ind_line)
{
	int		i;
	int		n_possibilities;
	char	**possibilities;
	char	**new_matrix;
	char	**solve;

	if (ind_line == 4)
		return (verify_final_matrix(input, matrix));
	possibilities = (char**)malloc(sizeof(char*) * 24);
	n_possibilities = get_poss(input, ind_line, possibilities);
	i = 0;
	while (i < n_possibilities)
	{
		new_matrix = update_matrix(ind_line, matrix, possibilities[i]);
		solve = solve_matrix(input, new_matrix, ind_line + 1);
		if (solve != NULL)
		{
			delete_possibilities(possibilities, n_possibilities);
			return (solve);
		}
		delete_matrix(new_matrix);
		i++;
	}
	delete_possibilities(possibilities, n_possibilities);
	return (NULL);
}
