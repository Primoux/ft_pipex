/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:24 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/30 16:30:53 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		j;

	if (argc < 5) // Check for minimum required arguments
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data)); // Allocate memory for data
	if (!data)
		return (1);
	ft_printf("%d\n", argc);
	if (init_data(data, argc, argv) == 1)
	{
		free(data);
		return (1);
	}
	ft_printf("Infile : %s\n", data->infile);
	if (data->args)
	{
		i = 0;
		while (data->args[i])
		{
			j = 0;
			while (data->args[i][j])
			{
				ft_printf("args[%d][%d] :%s\n", i, j, data->args[i][j]);
				j++;
			}
			i++;
		}
	}
	ft_printf("Outfile : %s\n", data->outfile);
	// Free all allocated memory
	if (data->args)
	{
		i = 0;
		while (data->args[i])
		{
			j = 0;
			while (data->args[i][j])
				free(data->args[i][j++]);
			free(data->args[i++]);
		}
		free(data->args);
	}
	free(data);
	return (0);
}
