/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 17:07:53 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/20 17:22:50 by mforstho      ########   odam.nl         */
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

static void	print_operation(t_operation op)
{
	static char	*t_op_array[] = {
		[SA] = "sa",
		[SB] = "sb",
		[SS] = "ss",
		[PA] = "pa",
		[PB] = "pb",
		[RA] = "ra",
		[RB] = "rb",
		[RR] = "rr",
		[RRA] = "rra",
		[RRB] = "rrb",
		[RRR] = "rrr",
	};

	ft_putendl_fd(t_op_array[op], STDOUT_FILENO);
}

static void	exec_op(t_operation op, t_stack **a, t_stack **b)
{
	static t_op_function	op_fn[] = {
	[SA] = sa,
	[SB] = sb,
	[SS] = ss,
	[PA] = pa,
	[PB] = pb,
	[RA] = ra,
	[RB] = rb,
	[RR] = rr,
	[RRA] = rra,
	[RRB] = rrb,
	[RRR] = rrr,
	};

	if (op_fn[op](a, b) == true)
		print_operation(op);
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
