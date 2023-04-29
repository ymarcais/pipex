/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:54:11 by ymarcais          #+#    #+#             */
/*   Updated: 2023/04/29 15:24:48 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>

# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>

# define EXIT_FAILURE 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
}			t_pipex;

/*From mini_libft*/
int		str_ncmp(char *str1, char *str2, int n);
char	*str_ndup(char *str, unsigned int n);
char	**str_split(char *str, char sep);
int		str_ichr(char *str, char c);

/* Utils*/
int		openfile(char *filename, int mode);
char	*path_join(char *path, char *bin);
char	*get_path(char *cmd, char **envp);
void	exec(char *cmd, char **envp);

/* Childs*/
void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, int argc, char **argv, char **envp);

/* Errors*/
void	msg_err(char *err);
void	check_cmd(char *cmd);
void	check_arg(int argc, char **envp);
void	close_pipes(t_pipex pipex);

#endif