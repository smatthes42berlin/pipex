/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:52:16 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 13:32:30 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_args_handling(t_pipex_data *data)
{
	// add stuff, otherwise same as below
	free_cmd_arg1_2(data);
	free_str_arr_null(data->path);
	return (-1);
}

int	free_cmd_arg1_2_path(t_pipex_data *data)
{
	free_cmd_arg1_2(data);
	free_str_arr_null(data->path);
	return (-1);
}

int	free_cmd_arg1(t_pipex_data *data)
{
	free_str_arr_null(data->cmd_arg_1);
	return (-1);
}
int	free_cmd_arg1_2(t_pipex_data *data)
{
	free_cmd_arg1(data);
	free_str_arr_null(data->cmd_arg_2);
	return (-1);
}
