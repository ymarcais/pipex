/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:22:12 by ymarcais          #+#    #+#             */
/*   Updated: 2023/04/29 14:36:07 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex = {0};

	check_arg(argc, envp);
	pipe(pipex.pipe_fd);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argc, argv, envp);
	close_pipes(pipex);
	waitpid(pipex.pid1, NULL, 0);
	wait(NULL);
	return (0);
}
