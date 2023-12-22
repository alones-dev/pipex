/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:15 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/22 14:36:16 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* TODO:
	- Check files OK
	- Check the command files (PATH= envp) OK
	- Create and manage pipe OK
	- Manage child (fork 0:)
	- Manage parent (fork 1:)
	- Wait process child & parent finish
	- Execute command (execve)
*/

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
	return (0);
}
