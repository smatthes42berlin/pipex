/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:52:16 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 15:05:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	split_cmd_args(char *cmd_args_str, char ***cmd_args_arr)
{
	*cmd_args_arr = ft_split(cmd_args_str, ' ');
	if (!(*cmd_args_arr))
		return (-1);
	return (1);
}

int	get_path(char *envp[], char ***path)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (-1);
	*path = ft_split((envp[i] + 5), ':');
	if (!(*path))
	{
		free_str_arr_null(*path);
		return (-1);
	}
	return (1);
}

int	check_cmd_access(t_pipex_data *data)
{
	int		i;
	char	*path;
	int		status;

	// check file direct access first
	data->exec_path_1 = NULL;
	i = 0;
	if (access(data->cmd_arg_1[0], X_OK) == 0)
	{
		data->exec_path_1 = data->cmd_arg_1[0];
		return (1);
	}
	while (data->path[i])
	{
		status = ft_join_n_str(&path, 3, data->path[i], "/", data->cmd_arg_1[0]);
		if (status == -1)
			return (-1);
		ft_printf_fd(2, "%s\n", data->cmd_arg_1[0]);
		ft_printf_fd(2, "%s\n", path);
		if (access(path, X_OK) == 0)
		{
			data->exec_path_1 = path;
			break ;
		}
		free(path);
		i++;
	}
	return (1);
}
