/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:06:54 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/09 14:44:53 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		return (free_split(args), close(fd[0]), close(fd[1]), perror("fd[0]"),
			0);
	if (dup2(fd[0], 0) == -1 || dup2(fd[1], 1) == -1)
		return (free_split(args), close(fd[0]), close(fd[1]), perror("dup2"),
			0);
	(close(fd[0]), close(fd[1]));
	execve(cmd, args, NULL);
	(free_split(args), perror("execve"), exit(1));
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
		return (free_split(args), close(fd[0]), close(fd[1]), perror("fd[1]"),
			0);
	if (dup2(fd[0], 0) == -1 || dup2(fd[1], 1) == -1)
		return (free_split(args), close(fd[0]), close(fd[1]), perror("dup2"),
			0);
	(close(fd[0]), close(fd[1]));
	execve(cmd, args, NULL);
	(free_split(args), perror("execve"), exit(1));
}

/* Execute all command and link them with pipe
@param path -> PATH environment variable
@param av -> main argv
@param fd -> the two open file descriptor
@return :
	0 : execution fail
	1 : all executions success
*/
int	manage_execution(char **path, char **av, int *fd)
{
	pid_t	pid;

	if (pipe(fd) == -1)
		return (perror("pipe"), 0);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 0);
	if (pid == 0)
		return (execute_child_process(path, av, fd));
	(close(fd[1]), pid = fork());
	if (pid == -1)
		return (perror("fork"), 0);
	if (pid == 0)
		return (execute_parent_process(path, av, fd));
	return (close(fd[0]), pid);
}

/* Main function */
int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	char	**path;
	char	*env;
	pid_t	pid;

	if (ac != 5)
		return (ft_putstr_fd("Command usage: ./pipex file1 cmd1 cmd2 file2\n",
				STDERR_FILENO), 1);
	path = NULL;
	env = ft_getenv("PATH", envp);
	if (env)
	{
		path = ft_split(env, ':');
		if (!path)
			return (0);
	}
	pid = manage_execution(path, av, fd);
	if (!pid)
		return (free_split(path), 1);
	return (free_split(path), wait_childs(pid));
}
