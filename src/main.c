/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/09 15:40:53 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// handle errors exactly like bash
// open first file
// check open successful
// redirect stdin to file
// create pip
// fork 1
// when in child1
// redirect stdout to pipe
// close pipes
// run first command
// fork again
// when in child
// redirect stdout to file
// redirect stdin to pipe
// run cmd
// in parent wait for both processes
// additionally, check with path variable if executables exists with access
// also check for error codes

//  ./pipex infile "grep a1" "wc -w" outfile
int	main(int argc, char *argv[], char *envp[])
{
	int fd_in;
	int fd_pipe[2];

	// if (argc != 5)
	// 	return (1);
	envp++;
	argc++;
	// handle opening problem in child
	printf("%s\n", argv[0]);
	if (pipe(fd_pipe) == -1)
	{
		perror("pipe could not be opened!\n");
		return (3);
	}
	int child_cmd1 = fork();
	if (child_cmd1 == -1)
	{
		perror("child could not be created!\n");
		return (4);
	}
	if (child_cmd1 == 0)
	{
		fd_in = open(argv[1], O_RDONLY);
		printf("%d\n", fd_in);
		if (dup2(fd_in, STDIN_FILENO) == -1)
		{
			perror("problem redirecting file descriptor in!\n");
			return (2);
		};
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
		{
			perror("problem redirecting file descriptor out!\n");
			return (2);
		};
		char *args[] = {"/usr/bin/cat", NULL};
		char *env[] = {NULL};
		close(fd_in);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		execve("/usr/bin/cat", args, env);
	}
	printf("Hello!\n");
	close(fd_pipe[1]);
	waitpid(child_cmd1, NULL, 0);
	char *args[] = {"/usr/bin/wc", "-l", NULL};
	char *env[] = {NULL};
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
	{
		perror("problem redirecting file descriptor out!\n");
		return (2);
	};
	execve("/usr/bin/wc", args, env);

	close(fd_pipe[0]);
}