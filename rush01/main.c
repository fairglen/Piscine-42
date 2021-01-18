/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:51:29 by iferreir          #+#    #+#             */
/*   Updated: 2021/01/17 18:54:54 by iferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**solve_matrix(int *input, char **matrix, int ind_line);
char	**matrix_init(void);
void	delete_matrix(char **matrix);
void	print_matrix(char **matrix);

int		string_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		verify_input(char *str)
{
	int i;
	int len;

	len = string_len(str);
	i = 1;
	while (i < len)
	{
		if (str[i] != ' ')
		{
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

int		*process_input(char *str)
{
	int i;
	int j;
	int n;
	int *input;

	input = (int*)malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			n = str[i] - '0';
			input[j] = n;
			j++;
		}
		i++;
	}
	return (input);
}

int		result(char *str)
{
	int		*input;
	char	**matrix;
	char	**new_matrix;

	matrix = matrix_init();
	input = process_input(str);
	new_matrix = solve_matrix(input, matrix, 0);
	delete_matrix(matrix);
	if (new_matrix == NULL)
	{
		write(1, "Error", 5);
		return (0);
	}
	else
	{
		print_matrix(new_matrix);
		delete_matrix(new_matrix);
		return (0);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (string_len(argv[1]) != 31 || verify_input(argv[1]) != 1)
		{
			write(1, "Error", 5);
			return (0);
		}
		else
		{
			result(argv[1]);
		}
	}
	else
	{
		write(1, "Error", 5);
		return (0);
	}
	return (0);
}
