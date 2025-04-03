/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:19:48 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/03 12:27:19 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*-------------------------------- INCLUDES --------------------------------*/
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>
/*-------------------------------- DEFINES --------------------------------*/

/*--------------------------------- ENUM ---------------------------------*/

/*-------------------------------- STRUCTS --------------------------------*/

typedef struct s_data
{
	char	**av;
	int		ac;
	int		id;
	char	*infile;
	int		fd_infile;
	char	*outfile;
	int		fd_outfile;
	char	***args;
	t_bool	here_doc;
	char	*limiter;
	int		cmd_count;
	char	*path;
	char	**split_path;
}			t_data;

/*------------------------------- FUNCTIONS -------------------------------*/
int			get_arg(t_data *data, char **argv);
int			init_data(t_data *data, int argc, char **argv, char **env);
char		*get_path(t_data *data, char **env);
void		destruct_all(t_data data);

#endif
