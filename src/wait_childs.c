/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:43:04 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/21 22:10:50 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_cmd(t_data data, int i)
{
	if (data.args[i][0] == NULL)
		ft_putendl_fd(": command not found", 2);
	else if (ft_strchr(data.args[i][0], '/') != NULL)
	{
		ft_putstr_fd(data.args[i][0], 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else
	{
		ft_putstr_fd(data.args[i][0], 2);
		ft_putendl_fd(": command not found", 2);
	}
}

static void	check_sig(t_data *data, int i, int status, int *exit_code)
{
	int	sig;

	waitpid(data->pid_children[i], &status, 0);
	if (WIFEXITED(status))
	{
		*exit_code = WEXITSTATUS(status);
		if (*exit_code == 127)
			check_cmd(*data, i);
		else if (*exit_code == 126)
			if (errno != 0)
				perror(data->args[i][0]);
	}
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		*exit_code = 128 + sig;
		if (sig == SIGTERM)
			ft_putendl_fd("Terminated", 2);
	}
}

int	wait_childs(t_data *data)
{
	int	i;
	int	exit_code;
	int	status;

	status = 0;
	i = -1;
	while (++i < data->cmd_count)
		check_sig(data, i, status, &exit_code);
	return (exit_code);
}
