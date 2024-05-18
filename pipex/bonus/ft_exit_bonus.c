/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:49 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/18 09:42:17 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(int i)
{
	if (i == 1)
	{
		perror("Error");
		exit(1);
	}
	else if (i == 2)
	{
		write(2, "Error: Bad Arguments\n", 22);
		exit(1);
	}
}
