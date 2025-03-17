/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:24 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/17 19:13:25 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

static int	get_arg(t_data *data, char **argv)
{
	int	i;

	i = 1;
	if (ft_strncmp("here_doc", argv[i], ft_strlen(argv[i])) == 0)
	{
		data->here_doc = TRUE;
		data->limiter = argv[2];
		i = i + 2;
	}
	if (data->ac > 5 && data->here_doc == FALSE)
		data->middle_cmd = malloc(data->ac - 3 * sizeof(char *));
	else if (data->ac > 5 && data->here_doc == TRUE)
		data->middle_cmd = malloc(data->ac - 4 * sizeof(char *));
	else
	{
		data->infile = argv[i];
		data->first_cmd = argv[i + 1];
		data->last_cmd = argv[i + 2];
		data->outfile = argv[i + 3];
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.ac = argc;
	get_arg(&data, argv);
	ft_printf("infile : %s\nfirst : %s\nlast : %s\noutfile : %s\n", data.infile,
		data.first_cmd, data.last_cmd, data.outfile);
}
