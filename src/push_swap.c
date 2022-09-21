/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:32 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/21 15:54:01 by mforstho      ########   odam.nl         */
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
	if (check_if_sorted(argc, &arr) == OK)
		return (EXIT_SUCCESS);
	if (bubble_sort_array(argc, &arr) != OK
		|| initialize_stack(&data, argv) != OK)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	set_stack_index(&data, argc, arr);
	ps_choose_sort(argc, &data);
	return (EXIT_SUCCESS);
}
