/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stacksize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:32:07 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:32:08 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Iterates through the list to determine the size of the list

#include "push_swap.h"

int	ps_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
