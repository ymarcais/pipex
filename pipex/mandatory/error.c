/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:55:27 by ymarcais          #+#    #+#             */
/*   Updated: 2023/04/29 14:20:54 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	msg_err(char *err)
{
	perror(err);
	exit (1);
}

void	check_cmd(char *cmd)
{
	if (!cmd)
	{
		write (2, "ERR_CMD", 7);
		exit (1);
	}
}

void	check_arg(int argc, char **envp)
{
	if (!*envp)
	{
		write(STDERR, "Pipex: environment not found\n", 29);
		exit(2);
	}
	if (argc != 5)
	{
		write(2, "ERR_CMD", 7);
		exit (1);
	}
	if (OUTFILE < 0)
	{
		write(STDERR, "ERR_OUTFILE", 11);
		exit (3);
	}
}
