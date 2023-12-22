/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:16:26 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/22 11:45:10 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* TODO:
	- Init struct
		* cmd1 & 2 check OK
		* args1 & 2 check OK
		* file1 & 2 check OK
	- Open files
		* check file1 & 2 with acces
		* open fd1 & 2
	- Create forks
		* create pipe
		* pid1 & 2
*/

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
	pipex->pid1 = -1;
	pipex->pid2 = -1;
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
