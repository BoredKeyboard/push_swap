/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_arr_sort_stack.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 14:29:30 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/20 15:46:30 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*initialize_array(int argc, char *argv[])
{
	int	i;
	int	tmp;
	int	*arr;

	arr = malloc((argc - 1) * sizeof(int));
	i = 0;
	tmp = 0;
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	while (i < argc - 1)
	{
		ft_atoi(argv[i + 1], &tmp);
		printf("%s  ", argv[i + 1]);	// tmp
		arr[i] = tmp;
		printf("%i\n", arr[i]);			// tmp
		i++;
	}
	return (arr);
}

int	check_if_sorted(int argc, int **arr)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (!((*arr)[i] < (*arr)[i + 1]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int	bubble_sort_array(int argc, int **arr)
{
	int	i;
	int	tmp;
	int	sorted;

	sorted = 0;
	printf("Starting sort\n");
	while (sorted != argc - 2)
	{
		sorted = 0;
		i = 0;
		while (i < argc - 2)
		{
			if ((*arr)[i] == (*arr)[i + 1])
				return (ERROR);
			if ((*arr)[i] > (*arr)[i + 1])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[i + 1];
				(*arr)[i + 1] = tmp;
			}
			else
				sorted++;
			i++;
		}
	}
	return (OK);
}

int	initialize_stack(t_data *data, char *argv[])
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i], &result) == false)
			return (EXIT_FAILURE);
		if (ps_stacknew_back(&data->a, result) == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	set_stack_index(t_data *data, int argc, int *arr)
{
	int		i;
	t_stack	*a;

	a = data->a;
	while (a)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (arr[i] == a->content)
				a->final_index = i;
			i++;
		}
		printf("%i | %i\n", a->content, a->final_index);
		a = a->next;
	}
}
