/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:24:08 by ymarcais          #+#    #+#             */
/*   Updated: 2023/04/29 14:14:49 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	close(pipex.pipe_fd[0]);
	pipex.infile = open(argv[1], O_RDONLY);
	if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
		msg_err("Error dup2 pipe_fd[1], STDOUT");
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		msg_err("Error dup2 infile, STDIN");
	exec(argv[2], envp);
	close(pipex.pipe_fd[1]);
}

void	second_child(t_pipex pipex, int argc, char **argv, char **envp)
{
	close(pipex.pipe_fd[1]);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, \
						S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
		msg_err("Error Dup2 pipe_fd[0] STDIN");
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		msg_err ("Error outfile STDOUT");
	exec(argv[3], envp);
	close(pipex.pipe_fd[0]);
}
