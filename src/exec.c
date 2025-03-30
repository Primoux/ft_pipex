/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:30:21 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/30 22:23:25 by enzo             ###   ########.fr       */
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
	if (get_path(data) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
