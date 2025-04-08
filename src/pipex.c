/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/08 15:53:10 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static void	first_cmd(t_fd *fd, char *file_name)
{
	int	infile;

	if (ft_strncmp(file_name, "/dev/stdin", 11) == 0)
		infile = STDIN_FILENO;
	else
	{
		infile = open(file_name, O_RDONLY);
		if (infile == -1)
		{
			perror("Error opening input file");
			exit(1);
		}
	}
	if (infile != STDIN_FILENO)
	{
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	dup2(fd->fd1[1], STDOUT_FILENO);
	close(fd->fd1[1]);
	close(fd->fd1[0]);
	close(fd->fd2[0]);
	close(fd->fd2[1]);
}

static void	middle_cmd(t_fd *fd)
{
	dup2(fd->fd1[0], STDIN_FILENO);
	close(fd->fd1[0]);
	dup2(fd->fd2[1], STDOUT_FILENO);
	close(fd->fd2[1]);
	close(fd->fd1[1]);
	close(fd->fd2[0]);
}

static void	last_cmd(t_fd *fd, char *file_name)
{
	int	outfile;

	if (ft_strncmp(file_name, "/dev/stdout", 12) == 0)
		outfile = STDOUT_FILENO;
	else
	{
		outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
		{
			perror("Error opening output file");
			exit(1);
		}
	}
	if (outfile != STDOUT_FILENO)
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	dup2(fd->fd1[0], STDIN_FILENO);
	close(fd->fd1[0]);
	close(fd->fd1[1]);
}

static char	*find_command_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

static void	exec_cmd(t_data *data, int i)
{
	char	*cmd_path;

	cmd_path = find_command_path(data->args[i][0], data->split_path);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(data->args[i][0], 2);
		exit(127);
	}
	execve(cmd_path, data->args[i], data->env);
	perror("Error executing command");
	free(cmd_path);
	ft_putstr_fd("Error executing: ", 2);
	ft_putendl_fd(data->args[i][0], 2);
	exit(126);
}

static void	prepare_pipe(t_data *data, t_fd *fd, int i)
{
	if (i == 0)
		first_cmd(fd, data->infile);
	else if (i == data->cmd_count - 1)
		last_cmd(fd, data->outfile);
	else
		middle_cmd(fd);
}

int	ft_pipex(t_data *data)
{
	t_fd	fd;
	int		i;
	pid_t	pid;
	int		status;

	i = 0;
	if (pipe(fd.fd1) == -1)
		return (1);
	while (data->args[i])
	{
		if (i < data->cmd_count - 1 && pipe(fd.fd2) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			prepare_pipe(data, &fd, i);
			exec_cmd(data, i);
			exit(1);
		}
		close(fd.fd1[1]);
		if (i < data->cmd_count - 1)
		{
			fd.fd1[0] = fd.fd2[0];
			fd.fd1[1] = fd.fd2[1];
		}
		else
		{
			close(fd.fd1[0]);
		}
		i++;
	}
	while (wait(&status) > 0)
		;
	return (WEXITSTATUS(status));
}
