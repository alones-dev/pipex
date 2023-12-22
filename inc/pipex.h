/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:35:54 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/22 12:27:25 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	*cmd1;
	char	*cmd2;
	char	**arg1;
	char	**arg2;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	int		pid;
}			t_pipex;

char		*ft_getenv(char *name, char **envp);
int			find_command(char **path, char **cmd);
int			init_pipex(t_pipex *pipex, char **av, char **envp);

#endif