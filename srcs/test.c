/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:18:15 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/21 15:12:36 by kdaumont         ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	// pid_t pid
	(void)av;
	(void)ac;
	// if (ac < 5)
	// 	exit(0);
	ft_printf("%s\n", ft_getenv("PATH", envp));
	return (0);
}
