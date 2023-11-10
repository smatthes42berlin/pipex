/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:52:16 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 10:34:04 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process_main(t_pipex_data *data)
{
	int	status_1;
	// int	status_2;
	int	res_wait_1;
	// int	res_wait_2;


	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	res_wait_1 = waitpid(data->child_1_pid, &status_1, 0);
	// res_wait_2 = waitpid(pid_child_2, &status_2, 0);
	if (WIFEXITED(status_1))
	{
		res_wait_1 = WEXITSTATUS(status_1);
		printf("exit status was %d\n", res_wait_1);
	}
	// if (WIFEXITED(status_2))
	// {
	// 	res_wait_2 = WEXITSTATUS(status_2);
	// 	printf("exit status was %d\n", res_wait_2);
	// }
	return (1);
}
