/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:52:16 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 10:32:47 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process_cmd2(t_pipex_data *data)
{
	// int	fd_out;
	close(data->fd_pipe[1]);
	return (1);
	// close(fd_pipe[1]);
	// fd_out = open(argv[3], O_WRONLY);
	// if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
	// {
	// 	perror("problem redirecting file descriptor in!\n");
	// 	return (2);
	// };
	// if (dup2(fd_out, STDOUT_FILENO) == -1)
	// {
	// 	perror("problem redirecting file descriptor out!\n");
	// 	return (2);
	// };
	// return (2);
	// args[] = {"/usr/bin/cat", NULL};
	// env[] = {NULL};
	// close(fd_out);
	// close(fd_pipe[0]);
	// close(fd_pipe[1]);
	// execve("/usr/bin/cat", args, env);
}
