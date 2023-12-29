/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:06:54 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/29 15:53:40 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Free the double array filled by split
@param split -> double array filled
*/
void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

/* Execute command given if the process is child
@param cmd -> shell command for execution
@param av -> shell command arguments for execution
@param fd_in -> first file descriptor, in file
@param fd_out -> second file descriptor, out file
@return :
	- 0 : execution fail
	- 1 : execution sucess
*/
int	command_execute(char *cmd, char *av, int fd_in, int fd_out)
{
	pid_t	pid;
	char **args;

	pid = fork();
	if (pid == -1)
		return (0);
	args = ft_split(av, ' ');
	if (!args)
		return (0);
	if (pid == 0)
	{
		if (dup2(fd_in, 0) == -1)
			return (0);
		if (dup2(fd_out, 1) == -1)
			return (0);
		if (execve(cmd, args, NULL) == -1)
			return (0);
	}
	waitpid(pid, NULL, 0);
	return (1);
}

/* Execute all command and link them with pipe
@param path -> PATH environment variable
@param av -> all commands from argv (av + 2 = skip files)
@param fd -> the two open file descriptor
@param nb_cmd -> commands amount in argv
@return :
	0 : execution fail
	1 : all executions success
*/
int	manage_execution(char **path, char **av, int *fd, int nb_cmd)
{
	int		i;
	char	*file;
	char	**cmd;

	if (pipe(fd) == -1)
		return (0);
	i = -1;
	while (++i < nb_cmd)
	{
		cmd = ft_split(av[i], ' ');
		if (!cmd)
			return (0);
		file = find_command(path, cmd);
		if (!file)
			return (0);
		if (!command_execute(file, av[i], fd[0], fd[1]))
			return (0);
		free(cmd);
	}
	return (1);
}

/* Main function */
int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	char	**path;

	if (ac < 5)
		return (1);
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] < 0)
		return (1);
	fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);
	if (fd[1] < 0)
		return (1);
	path = ft_split(ft_getenv("PATH", envp), ':');
	if (!manage_execution(path, av + 2, fd, ac - 3))
		return (1);
	return (0);
}
