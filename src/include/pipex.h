/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:19:48 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/17 18:57:27 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*-------------------------------- INCLUDES --------------------------------*/
# include "libft.h"
/*-------------------------------- DEFINES --------------------------------*/

/*--------------------------------- ENUM ---------------------------------*/

/*-------------------------------- STRUCTS --------------------------------*/

/// @brief Struct representing everything needed by the mlx
typedef struct s_data
{
	char	**av;
	int		ac;
	int		id;
	char	*infile;
	char	*outfile;
	char	*first_cmd;
	char	**middle_cmd;
	char	*last_cmd;
	t_bool	here_doc;
	char	*limiter;

}			t_data;

/*------------------------------- FUNCTIONS -------------------------------*/
#endif
