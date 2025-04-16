/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:26:44 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/16 17:05:35 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*find_command_path(char *cmd, char **paths, t_data *data)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (ft_strrchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK | X_OK) != 0)
		{
			execve(cmd_path, data->args[i], data->env);
			exit(127);
		}
	}
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
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

void	count_args(t_data *data)
{
	data->cmd_count = 0;
	while (data->args[data->cmd_count++])
		;
	data->cmd_count--;
}

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

int	get_arg(t_data *data, char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	data->args = ft_calloc((data->ac - 2 + 1), sizeof(char *));
	if (data->args == NULL)
		return (1);
	while (i < data->ac - 1)
	{
		data->args[j] = ft_split(argv[i], ' ');
		if (data->args[j] == NULL)
			return (1);
		i++;
		j++;
	}
	data->args[j] = NULL;
	data->infile = argv[1];
	data->outfile = argv[data->ac - 1];
	return (0);
}
