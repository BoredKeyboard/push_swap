/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 13:33:15 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 13:33:51 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_error	*get_error_ptr(void)
{
	static t_error	error = NO_ERROR;

	return (&error);
}

t_status	set_error(t_error error)
{
	*get_error_ptr() = error;
	if (error == NO_ERROR)
		return (OK);
	return (ERROR);
}

t_error	get_error(void)
{
	return (*get_error_ptr());
}

void	print_err(void)
{
	static char	*error_texts[] = {
	[NO_ERROR] = "NO_ERROR",
	};

	ft_putendl_fd(error_texts[get_error()], STDERR_FILENO);
}
