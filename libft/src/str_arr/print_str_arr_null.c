/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_arr_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:27:08 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 11:48:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib_main.h"

void	print_str_arr_null(char **arr)
{
	while (*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
}