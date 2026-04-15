/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:12:57 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/28 17:21:34 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	msg_exit(char *msg, int code)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(code);
}

char	**get_cmd_args(char *cmd)
{
	return (ft_split(cmd, ' '));
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
