/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:26:44 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/30 16:34:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	get_arg(t_data *data, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 2;
	j = 0;
	if (i < data->ac && ft_strncmp("here_doc", argv[i],
			ft_strlen("here_doc")) == 0)
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
		{
			while (--j >= 0)
			{
				k = 0;
				while (data->args[j][k])
					free(data->args[j][k++]);
				free(data->args[j]);
			}
			free(data->args);
			return (1);
		}
		i++;
		j++;
	}
	data->args[j] = NULL;
	data->infile = argv[1];
	data->outfile = argv[data->ac - 1];
	return (0);
}
