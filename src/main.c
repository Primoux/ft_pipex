/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:24 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/31 20:48:14 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;
	int		j;

	if (argc < 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (1);
	}
	if (init_data(&data, argc, argv, env) == 1)
	{
		if (data.args)
		{
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
		return (1);
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
	if (data.args)
	{
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
	free_tab_return_int(data.split_path, 0);
	return (0);
}
