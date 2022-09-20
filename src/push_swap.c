/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:32 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/20 15:59:40 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_value(int argc)
{
	int	i;
	int	max_value;

	i = 0;
	max_value = argc - 2;
	while (max_value != 0)
	{
		max_value >>= 1;
		i++;
	}
	return (i);
}

static unsigned int	get_digit_at_index(int i, unsigned int final_index)
{
	return ((final_index >> i) & 1);
}

static void	radix_sort(int argc, t_data *data)
{
	int	i;
	int	j;
	int	max_value;

	i = 0;
	max_value = get_max_value(argc);
	while (i < max_value)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (get_digit_at_index(i, data->a->final_index) == 0)
				pb(&data->a, &data->b);
			else
				ra(&data->a, &data->b);
			j++;
		}
		while (data->b != NULL)
			pa(&data->a, &data->b);
		i++;
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

	if (check_if_sorted(argc, &arr) != OK)
	{
		if (bubble_sort_array(argc, &arr) != OK)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}

	// printf("Sorted array: %i, %i, %i, %i, %i", arr[0], arr[1], arr[2], arr[3], arr[4]);
	// printf(" %i, %i, %i, %i, %i\n\n", arr[5], arr[6], arr[7], arr[8], arr[9]);

	initialize_stack(&data, argv);
	debug_print_stacks(data.a, data.b);

	set_stack_index(&data, argc, arr);

	printf("radix sort:\n");

	radix_sort(argc, &data);
	debug_print_stacks(data.a, data.b);

	// TMP
	// printf("\n");
	// printf("Highest: %i\nMax value: %i\n", (argc - 2), get_max_value(argc));
	return (EXIT_SUCCESS);
}


/*
5 & 7
101 & 111
101 = 5

a = 13 & 6
10101 & 00110
00100 = 4 = a 

14 = 10110
14 >> 3
     
   10

(14 >> i) & 1 =?= 0
101 & 1 = 1


& | ^ ~ >> <<

     



while (i < grootste index int in binary)
{
	while (j < aantal getallen in list a)
	{
		blabla

		j++;
		data->a = data->a.next;
	}
	i++;
}
*/