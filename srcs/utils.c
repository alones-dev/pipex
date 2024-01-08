/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:19:01 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/08 09:17:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Wait the childs process finish
@param pid -> 
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
