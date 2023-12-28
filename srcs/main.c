/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:15 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/28 12:00:09 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Execute the command for the first fork
@param pipex -> t_pipex struct pointer
@param envp -> program environment
@return :
	- 0 : fail execution
	- 1 : execution success
*/
int	command_execute_1(t_pipex *pipex, char **envp)
{
	char **env;

	env = ft_split(ft_getenv("PATH", envp), ':');
	if (!env)
		return (0);
	if (dup2(pipex->fd1, 0) == -1)
		return (0);
	if (dup2(pipex->fd2, 1) == -1)
		return (0);
	if (execve(find_command(env, &(pipex->cmd1)), pipex->arg1, NULL) == -1)
		return (0);
		
	return (1);
}

/* Execute the command for the second fork
@param pipex -> t_pipex struct pointer
@param envp -> program environment
@return :
	- 0 : fail execution
	- 1 : execution success
*/
int	command_execute_2(t_pipex *pipex, char **envp)
{
	char **env;

	env = ft_split(ft_getenv("PATH", envp), ':');
	if (!env)
		return (0);
	if (dup2(pipex->fd1, 0) == -1)
		return (0);
	if (dup2(pipex->fd2, 1) == -1)
		return (0);
	if (execve(find_command(env, &(pipex->cmd2)), pipex->arg2, NULL) == -1)
		return (0);
	
	return (1);
}

/* Main function */
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		fd[2];

	if (ac != 5)
		return (0);
	if (!init_pipex(&pipex, av, envp))
		return (0);
	if (!init_files(&pipex))
		return (0);
	if (init_fork(&pipex, fd))
		return (0);
	return (0);
}
