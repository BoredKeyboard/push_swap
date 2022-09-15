/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:32 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/15 15:57:16 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static int	*initialize_array(int argc, char *argv[])
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

static void	bubble_sort_array(int argc, int **arr)
{
	int	i;
	int	tmp;
	int	sorted;

	i = 0;
	tmp = 0;
	sorted = 0;
	while (sorted != argc - 2)
	{
		sorted = 0;
		i = 0;
		while (i < argc - 2)
		{
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
}

static int	initialize_stack(t_data *data, char *argv[])
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

static void	set_stack_index(t_data *data, int argc, int *arr)
{
	int	i;

	i = 0;
	while (data->a)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (arr[i] == data->a->content)
				data->a->final_index = i;
			i++;
		}
		printf("%i | %i\n", data->a->content, data->a->final_index);
		data->a = data->a->next;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		*arr;

	if (argc < 2)
		return (EXIT_SUCCESS);
	arr = initialize_array(argc, argv);
	if (arr == NULL)
		return (EXIT_FAILURE);

	printf("\n");						// tmp


	printf("Unsorted array: %i, %i, %i, %i, %i\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	bubble_sort_array(argc, &arr);

	printf("Sorted array: %i, %i, %i, %i, %i\n\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	initialize_stack(&data, argv);
	debug_print_stacks(data.a, data.b);

	set_stack_index(&data, argc, arr);

	// debug_print_stacks(data.a, data.b);

	// sa(&data.a, &data.b);
	// debug_print_stacks(data.a, data.b);

	// pb(&data.a, &data.b);
	// pb(&data.a, &data.b);
	// pb(&data.a, &data.b);
	// debug_print_stacks(data.a, data.b);

	// ra(&data.a, &data.b);
	// rb(&data.a, &data.b);
	// debug_print_stacks(data.a, data.b);

	// rra(&data.a, &data.b);
	// rrb(&data.a, &data.b);
	// debug_print_stacks(data.a, data.b);

	// sa(&data.a, &data.b);
	// debug_print_stacks(data.a, data.b);

	// pa(&data.a, &data.b);
	// pa(&data.a, &data.b);
	// pa(&data.a, &data.b);
	// debug_print_stacks(data.a, data.b);
	return (EXIT_SUCCESS);
}
