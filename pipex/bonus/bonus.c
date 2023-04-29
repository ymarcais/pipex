/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:22:23 by ymarcais          #+#    #+#             */
/*   Updated: 2023/04/29 15:20:53 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	i = 3;
	if (argc >= 5)
	{
		fd_in = openfile(argv[1], INFILE);
		fd_out = openfile(argv[argc - 1], OUTFILE);
		dup2(fd_in, STDIN);
		dup2(fd_out, STDOUT);
		redir(argv[2], envp, fd_in);
		while (i < argc - 2)
			redir(argv[i++], envp, 1);
		exec(argv[i], envp);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}
