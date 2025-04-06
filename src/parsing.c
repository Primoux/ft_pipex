/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:26:44 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/03 18:16:02 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

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
	if (i < data->ac && ft_strncmp("here_doc", argv[i],
			8) == 0)
	{
		data->here_doc = TRUE;
		data->limiter = argv[2];
		i = 3;
		data->ac--;
	}
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
