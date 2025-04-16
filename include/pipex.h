/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:19:48 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/16 01:52:45 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*-------------------------------- INCLUDES --------------------------------*/
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
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

typedef struct s_fd
{
	int		fd1[2];
	int		fd2[2];
}			t_fd;

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
	char	**env;
	char	*limiter;
	int		cmd_count;
	char	*path;
	char	**split_path;
	pid_t	*pid_children;
}			t_data;

/*------------------------------- FUNCTIONS -------------------------------*/
int			get_arg(t_data *data, char **argv);
int			init_data(t_data *data, int argc, char **argv, char **env);
char		*get_path(char **env);
void		free_all(t_data *data);
int			ft_pipex(t_data *data);
void		count_args(t_data *data);
void		close_all(t_fd *fd);
char		*find_command_path(char *cmd, char **paths, t_data *data);
void		first_cmd(t_fd *fd, char *file_name, t_data *data);
void		middle_cmd(t_fd *fd);
void		last_cmd(t_fd *fd, char *file_name, t_data *data);

#endif
