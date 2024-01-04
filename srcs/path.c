/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:36:01 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/04 11:02:28 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Get the environment variable given
@param name -> environment variable name
@param envp -> program environment
@return :
	- char: environment variable
	- NULL: nothing find
*/
char	*ft_getenv(char *name, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

/* Add to back of environment path the '/' & the command
@param new -> empty allocated str which receive the command path
@param path -> path on environment variable (ex: /usr/bin)
@param cmd -> shell command (ex: ls)
*/
void	cmd_cat(char *new, char *path, char *cmd)
{
	ft_strlcat(new, path, -1);
	ft_strlcat(new, "/", -1);
	ft_strlcat(new, cmd, -1);
}

/* Check if the shell command given is valid on the environment path finded
@param path -> array of all path on environment variable
@param cmd -> shell command checked (ex: ls)
@return :
	- 0: cmd not valid
	- 1: cmd finded
*/
char	*find_command(char **path, char *cmd)
{
	char	*new;
	int		i;

	i = 0;
	while (path[i])
	{
		new = ft_calloc(ft_strlen(path[i]) + ft_strlen(cmd) + 2, sizeof(char));
		if (!new)
			return (NULL);
		cmd_cat(new, path[i], cmd);
		if (access(new, F_OK | X_OK) == -1)
		{
			free(new);
			new = NULL;
		}
		else
			break ;
		i++;
	}
	if (!new)
		return (NULL);
	return (new);
}

/* Function to execute code for the child process
@param path -> array of all path on environment variable
@param av -> shell command arguments for execution
@param fd -> two file descriptor
@return :
	- 0 : execution fail
	- 1 : execution sucess
*/
int	execute_child_process(char **path, char **av, int *fd)
{
	char	**cmd;
	char	*file;

	cmd = ft_split(av[2], ' ');
	if (!cmd)
		return (0);
	file = find_command(path, cmd[0]);
	free_split(cmd);
	if (!file)
		return (close(fd[0]), close(fd[1]), 0);
	if (!command_execute_one(file, av[2], av[1], fd))
		return (free(file), 0);
	return (1);
}

/* Function to execute code for the child process
@param path -> array of all path on environment variable
@param av -> shell command arguments for execution
@param fd -> two file descriptor
@return :
	- 0 : execution fail
	- 1 : execution sucess
*/
int	execute_parent_process(char **path, char **av, int *fd)
{
	char	**cmd;
	char	*file;

	cmd = ft_split(av[3], ' ');
	if (!cmd)
		return (0);
	file = find_command(path, cmd[0]);
	free_split(cmd);
	if (!file)
		return (close(fd[0]), close(fd[1]), 0);
	if (!command_execute_two(file, av[3], av[4], fd))
		return (free(file), 0);
	return (1);
}
