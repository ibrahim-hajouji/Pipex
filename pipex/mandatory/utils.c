/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:26:27 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/12 19:56:38 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*fill(char *str, int count, int index)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	if (str[index] == 34 || str[index] == 39)
		index++;
	while (i < count)
	{
		result[i] = str[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}

int	handle_quote(char *s, int i, char c)
{
	while (s[i] && s[i] != c)
	{
		if (s[i] == 34 || s[i] == 39)
		{
			i++;
			while (s[i] != 34 && s[i] != 39 && s[i])
				i++;
			if (s[i] == 34 || s[i] == 39)
				i++;
		}
		else
			i++;
	}
	return (i);
}
