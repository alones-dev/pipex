/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:15 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/22 11:43:04 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* TODO:
	- Check files
	- Check the command files (PATH= envp)
	- Create and manage pipe
	- Manage child (fork 0:)
	- Manage parent (fork 1:)
	- Wait process child & parent finish
	- Execute command (execve)
*/

/* Main function */
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (0);
	init_pipex(&pipex, av, envp);
	return (0);
}
