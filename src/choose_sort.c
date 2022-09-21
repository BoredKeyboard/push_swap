/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 15:50:15 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/21 15:52:36 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_choose_sort(int argc, t_data *data)
{
	if (argc - 1 == 2)
		exec_op(SA, &data->a, &data->b);
	else if (argc - 1 == 3)
		ps_hc_three(&data->a, &data->b);
	else if (argc - 1 == 4)
		ps_hc_four(&data->a, &data->b);
	else if (argc - 1 == 5)
		ps_hc_five(&data->a, &data->b);
	else
		radix_sort(argc, data);
}
