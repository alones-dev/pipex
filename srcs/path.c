/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:36:01 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/22 10:36:56 by kdaumont         ###   ########.fr       */
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

void	cmd_cat(char *new, char *path, char *cmd)
{
	ft_strlcat(new, path, -1);
	ft_strlcat(new, "/", -1);
	ft_strlcat(new, cmd, -1);
}

int	find_command(char **path, char **cmd)
{
	char	*new;
	int		i;

	i = 0;
	while (path[i])
	{
		new = ft_calloc(ft_strlen(path[i]) + ft_strlen(*cmd) + 2, sizeof(char));
		if (!new)
			return (0);
		cmd_cat(new, path[i], *cmd);
		if (access(new, F_OK | X_OK) == -1)
		{
			new = NULL;
			free(new);
		}
		else
		{
			*cmd = new;
			break ;
		}
		i++;
	}
	if (!new)
		return (0);
	return (1);
}
