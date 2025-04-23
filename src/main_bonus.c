/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:24 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/23 01:00:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	t_fd	fd;
	int		return_value;

	if (argc < 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 [...] outfile\n", argv[0]);
		return (1);
	}
	data.env = env;
	if (init_data(&data, argc, argv, &fd) == 1)
	{
		write(STDERR_FILENO, "Init error\n", 11);
		free_all(&data);
		return (1);
	}
	return_value = ft_pipex(&data, &fd);
	free_all(&data);
	close_all(&fd);
	return (return_value);
}
