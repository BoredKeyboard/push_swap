/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_op.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 14:22:48 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/21 14:22:59 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	exec_op(t_operation op, t_stack **a, t_stack **b)
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