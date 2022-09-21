/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 17:07:53 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/21 14:23:27 by mforstho      ########   odam.nl         */
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

void	radix_sort(int argc, t_data *data)
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
				exec_op(PB, &data->a, &data->b);
			else
				exec_op(RA, &data->a, &data->b);
			j++;
		}
		while (data->b != NULL)
			exec_op(PA, &data->a, &data->b);
		i++;
	}
}
