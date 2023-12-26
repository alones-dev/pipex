/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:16:26 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/26 11:33:03 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Initialize the base structure
@param pipex -> t_pipex struct pointer
*/
void	init_struct(t_pipex *pipex)
{
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->arg1 = NULL;
	pipex->arg2 = NULL;
	pipex->file1 = NULL;
	pipex->file1 = NULL;
	pipex->fd1 = -1;
	pipex->fd2 = -1;
	pipex->pid = -1;
}

/* Initialize correctly all structure values and check if the two command are valid
@param pipex -> t_pipex struct pointer
@param av -> main function arguments
@param envp -> main function environment variables
@return :
	- 0 : error
	- 1 : init success
*/
int	init_pipex(t_pipex *pipex, char **av, char **envp)
{
	char	**arg1;
	char	**arg2;
	char	**env;

	init_struct(pipex);
	env = ft_split(ft_getenv("PATH", envp), ':');
	if (!env)
		return (0);
	arg1 = ft_split(av[2], ' ');
	if (!arg1)
		return (0);
	pipex->cmd1 = arg1[0];
	if (!find_command(env, &(pipex->cmd1)))
		return (0);
	pipex->arg1 = arg1;
	arg2 = ft_split(av[3], ' ');
	if (!arg2)
		return (0);
	pipex->cmd2 = arg2[0];
	if (!find_command(env, &(pipex->cmd2)))
		return (0);
	pipex->arg2 = arg2;
	pipex->file1 = av[1];
	pipex->file2 = av[4];
	return (1);
}

/* Initialize & create the pipe and the fork
@param pipex -> t_pipex struct pointer
@param fd[2] -> files descriptor for the pipe
@return :
	- 0 : pipe or fork invalid
	- 1 : fork & pipe success
*/
int	init_fork(t_pipex *pipex, int fd[2])
{
	if (pipe(fd) == -1)
		return (0);
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (0);
	if (pipex->pid == 0)
	{
	}
	else
	{
	}
	return (1);
}

/* Open the two files and put it in the structure if are valids
@param pipex -> t_pipex struct pointer
@return :
	- 0 : fd invalid
	- 1 : fds open
*/
int	init_files(t_pipex *pipex)
{
	int fd1;
	int fd2;

	if (access(pipex->file1, F_OK | R_OK) == -1)
		return (0);
	fd1 = open(pipex->file1, O_RDONLY);
	if (fd1 == -1)
		return (0);
	fd2 = open(pipex->file2, O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR);
	if (fd2 == -1)
		return (0);
	pipex->fd1 = fd1;
	pipex->fd2 = fd2;
	return (1);
}
