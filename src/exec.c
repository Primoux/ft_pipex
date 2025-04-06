/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:30:21 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/03 18:12:04 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_data(t_data *data, int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	data->ac = argc;
	data->av = argv;
	data->here_doc = FALSE;
	data->split_path = NULL;
	if (get_arg(data, argv) == 1)
		return (1);
	data->path = get_path(env);
	data->split_path = ft_split(data->path, ':');
	if (data->split_path == NULL)
		return (1);
	while (data->split_path[i])
		i++;
	i--;
	while (i >= 0)
	{
		data->split_path[i] = str_free_to_join(data->split_path[i], "/");
		if (data->split_path[i] == NULL)
			return (1);
		i--;
	}
	return (0);
}
