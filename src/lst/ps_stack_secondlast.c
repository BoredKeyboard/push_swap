/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack_secondlast.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:32:49 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:51:27 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_stack_secondlast(t_stack *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
