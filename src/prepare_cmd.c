/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:44:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/20 15:24:27 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_fd *fd, char *file_name, t_data *data)
{
	int	infile;

	if (ft_strncmp(file_name, "/dev/stdin", 10) == 0)
		infile = STDIN_FILENO;
	else
	{
		infile = open(file_name, O_RDONLY);
		if (infile == -1)
			error_occured(fd, data, file_name);
	}
	if (infile != STDIN_FILENO)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
		{
			close(infile);
			error_occured(fd, data, "dup2");
		}
		close(infile);
	}
	if (dup2(fd->fd2[1], STDOUT_FILENO) == -1)
		error_occured(fd, data, "dup2");
	close_all(fd);
}

void	middle_cmd(t_fd *fd, t_data *data)
{
	if (dup2(fd->fd1[0], STDIN_FILENO) == -1)
		error_occured(fd, data, "dup2");
	if (dup2(fd->fd2[1], STDOUT_FILENO) == -1)
		error_occured(fd, data, "dup2");
	close_all(fd);
}

void	last_cmd(t_fd *fd, char *file_name, t_data *data)
{
	int	outfile;

	if (ft_strncmp(file_name, "/dev/stdout", 11) == 0)
		outfile = STDOUT_FILENO;
	else
	{
		outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			error_occured(fd, data, file_name);
	}
	if (outfile != STDOUT_FILENO)
	{
		if (dup2(outfile, STDOUT_FILENO) == -1)
		{
			close(outfile);
			error_occured(fd, data, "dup2");
		}
		close(outfile);
	}
	if (dup2(fd->fd1[0], STDIN_FILENO) == -1)
		error_occured(fd, data, "dup2");
	close_all(fd);
}
