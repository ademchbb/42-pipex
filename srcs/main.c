/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:45:49 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:36:36 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	init_pipex(t_pipex *p, char **argv, char **envp)
{
	p->envp = envp;
	p->file_in = open(argv[1], O_RDONLY);
	if (p->file_in < 0)
		error_exit(argv[1]);
	p->file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->file_out < 0)
		error_exit(argv[4]);
	if (pipe(p->pipe_fd) < 0)
		error_exit("pipe");
}

static int	wait_children(pid_t pid1, pid_t pid2)
{
	int	status;

	status = 0;
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		msg_exit("Usage: ./pipex file1 cmd1 cmd2 file2", 1);
	init_pipex(&p, argv, envp);
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork");
	if (pid1 == 0)
		child_one(&p, argv[2]);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork");
	if (pid2 == 0)
		child_two(&p, argv[3]);
	close(p.pipe_fd[0]);
	close(p.pipe_fd[1]);
	close(p.file_in);
	close(p.file_out);
	return (wait_children(pid1, pid2));
}
