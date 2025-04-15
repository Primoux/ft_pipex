/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:44:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/15 15:45:21 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_fd *fd, char *file_name, t_data *data)
{
	int	infile;

	if (ft_strncmp(file_name, "/dev/stdin", 11) == 0)
		infile = STDIN_FILENO;
	else
	{
		infile = open(file_name, O_RDONLY);
		if (infile == -1)
		{
			perror(file_name);
			free_all(data);
			close_all(fd);
			exit(1);
		}
	}
	if (infile != STDIN_FILENO)
	{
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	dup2(fd->fd2[1], STDOUT_FILENO);
	close(fd->fd1[0]);
	close(fd->fd1[1]);
	close(fd->fd2[0]);
	close(fd->fd2[1]);
}

void	middle_cmd(t_fd *fd)
{
	dup2(fd->fd1[0], STDIN_FILENO);
	dup2(fd->fd2[1], STDOUT_FILENO);
	close(fd->fd1[0]);
	close(fd->fd1[1]);
	close(fd->fd2[0]);
	close(fd->fd2[1]);
}

void	last_cmd(t_fd *fd, char *file_name, t_data *data)
{
	int	outfile;

	if (ft_strncmp(file_name, "/dev/stdout", 12) == 0)
		outfile = STDOUT_FILENO;
	else
	{
		outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
		{
			perror(file_name);
			free_all(data);
			close_all(fd);
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
	close(fd->fd2[0]);
	close(fd->fd2[1]);
}
