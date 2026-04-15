/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:23:25 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/28 17:21:49 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		pipe_fd[2];
	int		file_in;
	int		file_out;
	char	**envp;
}	t_pipex;

char	*get_cmd_path(char *cmd, char **envp);
char	**get_cmd_args(char *cmd);
void	child_one(t_pipex *p, char *cmd);
void	child_two(t_pipex *p, char *cmd);
void	error_exit(char *msg);
void	msg_exit(char *msg, int code);
void	free_tab(char **tab);

#endif