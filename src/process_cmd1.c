/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:52:16 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 10:51:25 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process_cmd1(t_pipex_data *data)
{
	int		fd_in;

	close(data->fd_pipe[0]);
	fd_in = open(data->infile, O_RDONLY);
    perror("fdsag");
	if (fd_in == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror(strerror(errno));
		perror("cp 1 problem redirecting file descriptor in!\n");
		exit(2);
	};
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
	{
		perror(strerror(errno));
		perror("cp 2 problem redirecting file descriptor out!\n");
		exit(2);
	};
	// execve(cmd_args[0], cmd_args, envp);
	// split the function call and arguments
	// pass everything to execve
	return (2);
	// args[] = {"/usr/bin/cat", NULL};
	// env[] = {NULL};
	// close(fd_in);
	// close(fd_pipe[0]);
	// close(fd_pipe[1]);
	// execve("/usr/bin/cat", args, env);
}
