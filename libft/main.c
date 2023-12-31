/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:35:25 by smatthes          #+#    #+#             */
/*   Updated: 2023/11/15 17:06:35 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

int	main(void)
{
	char	**res;
	char	*str;
	int		i;

	i = 0;
	str = "awk a's''sf''af''  '{Printf $1}' '' ''";
	res = ft_split_single_quotes(str, ' ');
	while ((res[i]))
	{
		ft_printf("%s$\n", res[i]);
		i++;
	}
	ft_printf("DONE!\n");
	free_str_arr_null(res);
}
