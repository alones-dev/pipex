/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:06:54 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/29 11:22:19 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int command_execute(char *cmd, char **args, int fd_in, int fd_out)
{
	pid_t pid;

	pid = fork();
	if (!args)
		return (0);
	if (pid == -1)
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

int manage_execution(char **path, char **av, int *fd, int nb_cmd)
{
	int i;
	char *file;
	char **cmd;
	
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
		if (!command_execute(file, cmd, fd[0], fd[1]))
			return (0);
		free(cmd);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	char **path;

	if (ac < 5)
		return (1);
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] < 0)
		return (1);
	fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR);
	if (fd[1] < 0)
		return (1);
	path = ft_split(ft_getenv("PATH", envp), ':');
	if (!manage_execution(path, av + 2, fd, ac - 3))
		return (1);
	return (0);
}