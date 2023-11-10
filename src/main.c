/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:07:51 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 14:58:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// input readonly
// output writeonly
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
// truncate outfile
// undefined behaviour when same filename

// protect wait pid (could return -1)

//  ./pipex infile "grep a1" "wc -w" outfile
int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_data data;

	if (handle_args(&data, argc, argv, envp) == -1)
		return (1);
	print_pipex_data(&data);
	free_args_handling(&data);

	// // handle opening problem in child
	// if (pipe(data.fd_pipe) == -1)
	// {
	// 	perror(strerror(errno));
	// 	perror("pipe could not be opened!\n");
	// 	return (3);
	// }
	// data.child_1_pid = fork();
	// if (data.child_1_pid == -1)
	// {
	// 	perror(strerror(errno));
	// 	perror("child could not be created!\n");
	// 	return (4);
	// }
	// if (data.child_1_pid == 0)
	// {
	// 	process_cmd1(&data);
	// }
	// else
	// {
	// 	data.child_2_pid = fork();
	// 	if (data.child_2_pid == -1)
	// 	{
	// 		perror(strerror(errno));
	// 		perror("child could not be created!\n");
	// 		return (4);
	// 	}
	// 	if (data.child_2_pid == 0)
	// 	{
	// 		process_cmd2(&data);
	// 	}
	// 	else
	// 	{
	// 		return (process_main(&data));
	// 	}
	// }
}