/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:32 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/20 17:20:18 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		*arr;

	if (argc < 2)
		return (EXIT_SUCCESS);
	arr = initialize_array(argc, argv);
	if (arr == NULL)
		return (EXIT_FAILURE);
	if (check_if_sorted(argc, &arr) != OK)
	{
		if (bubble_sort_array(argc, &arr) != OK
			|| initialize_stack(&data, argv) != OK)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	set_stack_index(&data, argc, arr);
	radix_sort(argc, &data);
	// debug_print_stacks(data.a, data.b);
	return (EXIT_SUCCESS);
}
