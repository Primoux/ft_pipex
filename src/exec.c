/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:30:21 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/30 16:33:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->ac = argc;
	data->av = argv;
	data->here_doc = FALSE;
	if (get_arg(data, argv) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	// if (get_path(data) == 1)
	// {
	// 	write(STDERR_FILENO, "Error\n", 6);
	// 	return (1);
	// }
	return (0);
}
