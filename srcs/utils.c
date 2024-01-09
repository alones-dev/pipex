/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:19:01 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/09 11:08:35 by kdaumont         ###   ########.fr       */
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

/* Wait the childs process finish
@param pid -> pid use for the commands
@return -> error code or state code
*/
int	wait_childs(int pid)
{
	int	wstatus;
	int	code;

	while (errno != ECHILD)
		if (wait(&wstatus) == pid && WIFEXITED(wstatus))
			code = WEXITSTATUS(wstatus);
	if (pid == -1)
		return (127);
	return (code);
}
