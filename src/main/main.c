/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:24 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/21 22:04:32 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

static int	get_arg(t_data *data, char **argv)
{
	int	i;
	int	j;

	data->here_doc = FALSE;
	i = 0;
	j = 0;
	if (ft_strncmp("here_doc", argv[i], ft_strlen(argv[i])) == 0)
	{
		data->here_doc = TRUE;
		data->limiter = argv[2];
		i = i + 2;
		data->ac--;
	}
	data->args = malloc((data->ac - 2) * (sizeof(char *)));
	if (data->args == NULL)
		return (1);
	i = 2;
	while (i < data->ac - 1)
	{
		data->args[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	data->args[j] = NULL;
	data->infile = argv[1];
	data->outfile = argv[data->ac - 1];
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd[2];
	int		pid1;
	int		pid2;
	int		j;
	int		i;

	data.ac = argc;
	if (get_arg(&data, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	data.fd_infile = open(data.infile, O_RDONLY);
	data.fd_outfile = open(data.outfile, O_RDONLY);
	if (pipe(fd) == -1)
	{
		ft_printf("Error on the pipe\n");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		ft_printf("Error on pid1\n");
		return (2);
	}
	if (pid1 == 0)
	{
		dup2(data.fd_infile, 0);
		close(data.fd_infile);
		dup2(data.fd_outfile, 1);
		close(data.fd_outfile);
		execve("/usr/bin/rhjhegfues");
	}
	// ft_printf("Infile : %s\n", data.infile);
	// if (data.args)
	// {
	// 	i = 0;
	// 	while (data.args[i])
	// 	{
	// 		j = 0;
	// 		while (data.args[i][j])
	// 		{
	// 			ft_printf("args[%d][%d] :%s\n", i, j, data.args[i][j]);
	// 			j++;
	// 		}
	// 		i++;
	// 	}
	// }
	// ft_printf("Outfile : %s\n", data.outfile);
	i = 0;
	while (data.args[i])
	{
		j = 0;
		while (data.args[i][j])
			free(data.args[i][j++]);
		free(data.args[i++]);
	}
	free(data.args);
}
