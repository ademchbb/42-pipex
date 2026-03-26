/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:19:00 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/25 18:11:40 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_cmd(t_pipex *p, char *cmd)
{
	char	**args;
	char	*path;

	args = get_cmd_args(cmd);
	if (!args || !args[0])
	{
		free_tab(args);
		error_exit("command not found");
	}
	path = get_cmd_path(args[0], p->envp);
	if (!path)
	{
		free_tab(args);
		error_exit("command not found");
	}
	execve(path, args, p->envp);
	free(path);
	free_tab(args);
	error_exit("execve failed");
}

void	child_one(t_pipex *p, char *cmd)
{
	dup2(p->file_in, STDIN_FILENO);
	dup2(p->pipe_fd[1], STDOUT_FILENO);
	close(p->pipe_fd[0]);
	close(p->pipe_fd[1]);
	exec_cmd(p, cmd);
}

void	child_two(t_pipex *p, char *cmd)
{
	dup2(p->pipe_fd[0], STDIN_FILENO);
	dup2(p->file_out, STDOUT_FILENO);
	close(p->pipe_fd[0]);
	close(p->pipe_fd[1]);
	exec_cmd(p, cmd);
}
