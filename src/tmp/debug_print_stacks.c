/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_print__stacks.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:33:08 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/15 15:22:10 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	debug_print_stacks(t_stack *a, t_stack *b)
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