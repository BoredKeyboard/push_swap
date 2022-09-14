/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:32 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 17:22:52 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	debug_print_stacks(t_stack *a, t_stack *b)
{
	size_t	i;

	i = 0;
	printf("\ta\tb\n");
	while (a != NULL || b != NULL)
	{
		printf("%-7zu|", i);
		if (a != NULL)
		{
			printf("%-7d", a->content);
			a = a->next;
		}
		else
			printf("%-7.0i", 0);
		printf("|");
		if (b != NULL)
		{
			printf("%-8d", b->content);
			b = b->next;
		}
		else
			printf("\t\t");
		printf("\n");
		i++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;
	int		result;

	if (argc < 2)
		return (EXIT_SUCCESS);
	i = 1;
	result = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i], &result) == false)
			return (EXIT_FAILURE);
		if (ps_stacknew_back(&data.a, result) == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	debug_print_stacks(data.a, data.b);

	sa(&data.a, &data.b);
	debug_print_stacks(data.a, data.b);

	pb(&data.a, &data.b);
	pb(&data.a, &data.b);
	pb(&data.a, &data.b);
	debug_print_stacks(data.a, data.b);

	ra(&data.a, &data.b);
	rb(&data.a, &data.b);
	debug_print_stacks(data.a, data.b);

	rra(&data.a, &data.b);
	rrb(&data.a, &data.b);
	debug_print_stacks(data.a, data.b);

	sa(&data.a, &data.b);
	debug_print_stacks(data.a, data.b);

	pa(&data.a, &data.b);
	pa(&data.a, &data.b);
	pa(&data.a, &data.b);
	debug_print_stacks(data.a, data.b);

	return (EXIT_SUCCESS);
}
