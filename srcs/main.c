/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:15 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/26 12:01:31 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* TODO:
	- Check files OK
	- Check the command files (PATH= envp) OK
	- Create and manage pipe OK
	- Manage child (fork 0:)
	- Manage parent (fork 1:)
	- Execute command (execve)
	- Wait process child & parent finish
*/

int	command_execute(t_pipex *pipex)
{
	if (dup2(pipex->fd1, 0) == -1)
		return (0);
	if (dup2(pipex->fd2, 1) == -1)
		return (0);
	if (execve(pipex->cmd1, pipex->arg1, NULL) == -1)
		return (0);
	return (1);
}

/* Main function */
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int fd[2];

	if (ac != 5)
		return (0);
	if (!init_pipex(&pipex, av, envp))
		return (0);
	if (!init_files(&pipex))
		return (0);
	if (init_fork(&pipex, fd))
		return (0);
	waitpid(pipex.pid, NULL, 0);
	return (0);
}
