/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:06:54 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/03 10:44:36 by kdaumont         ###   ########.fr       */
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
@param file -> first file to open
@param fd -> two file descriptor
@return :
	- 0 : execution fail
	- 1 : execution sucess
*/
int	command_execute_one(char *cmd, char *av, char *file, int *fd)
{
	char	**args;

	args = ft_split(av, ' ');
	if (!args)
		return (free_split(args), 0);
	close(fd[0]);
	fd[0] = open(file, O_RDONLY);
	if (fd[0] < 0)
		return (perror("fd[0]"), 0);
	if (dup2(fd[0], 0) == -1 || dup2(fd[1], 1) == -1)
		return (perror("dup2"), 0);
	(close(fd[0]), close(fd[1]));
	if (execve(cmd, args, NULL) == -1)
		return (perror("execve"), 0);
	return (free_split(args), 1);
}

/* Execute command given if the process is child
@param cmd -> shell command for execution
@param av -> shell command arguments for execution
@param file -> first file to open
@param fd -> two file descriptor
@return :
	- 0 : execution fail
	- 1 : execution sucess
*/
int	command_execute_two(char *cmd, char *av, char *file, int *fd)
{
	char	**args;

	args = ft_split(av, ' ');
	if (!args)
		return (free_split(args), 0);
	close(fd[1]);
	fd[1] = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);
	if (fd[1] < 0)
		return (perror("fd[1]"), 0);
	if (dup2(fd[0], 0) == -1 || dup2(fd[1], 1) == -1)
		return (perror("dup2"), 0);
	(close(fd[0]), close(fd[1]));
	if (execve(cmd, args, NULL) == -1)
		return (perror("execve"), 0);
	return (free_split(args), 1);
}

/* Execute all command and link them with pipe
@param path -> PATH environment variable
@param av -> all commands from argv (av + 2 = skip files)
@param fd -> the two open file descriptor
@return :
	0 : execution fail
	1 : all executions success
*/
int	manage_execution(char **path, char **av, int *fd)
{
	pid_t	pid;
	char	**cmd;
	char	*file;

	if (pipe(fd) == -1)
		return (perror("pipe"), 0);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 0);
	cmd = ft_split(av[2], ' ');
	if (!cmd)
		return (0);
	file = find_command(path, cmd);
	if (pid == 0)
		if (command_execute_one(file, av[2], av[1], fd) == -1)
			return (0);
	free_split(cmd);
	cmd = ft_split(av[3], ' ');
	if (!cmd)
		return (0);
	file = find_command(path, cmd);
	if (pid != 0)
		if (command_execute_two(file, av[3], av[4], fd) == -1)
			return (0);
	return (free_split(cmd), 1);
}

/* Main function */
int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	char	**path;

	if (ac < 5)
		return (ft_putstr_fd("Command usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO),
			1);
	path = ft_split(ft_getenv("PATH", envp), ':');
	if (!path)
		return (free_split(path), 0);
	if (!manage_execution(path, av, fd))
		exit(1);
	return (free_split(path), 0);
}
