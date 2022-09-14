/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stacknew.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:32:02 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:32:03 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns a new element with the content data

#include "push_swap.h"

t_stack	*ps_stacknew(int data)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (lst == NULL)
		return (NULL);
	lst->content = data;
	lst->next = NULL;
	return (lst);
}
