/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_n_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/10 15:06:57 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

// n must contain space for null byte
int	ft_join_n_str(char **res, int num, ...)
{
	va_list	args;
	char	*next_str;
	char	*tmp;
	int		i;
	int		status;

	va_start(args, num);
	if (num <= 0)
	{
		return (1);
		va_end(args);
	}
	*res = NULL;
	i = 0;
	while (i < num)
	{
		next_str = va_arg(args, char *);
		tmp = *res;
		status = ft_str_n_join_int(tmp, next_str, 0, res);
		free(tmp);
		if (status == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (1);
}
