/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:32 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/15 16:49:33 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*allocation(char *str, char c, int index)
{
	char	*result;
	int		j;
	int		count;

	count = 0;
	j = index;
	while (str[j])
	{
		if (str[j] == 34 || str[j] == 39)
		{
			j++;
			while (str[j] != 39 && str[j] != 34)
			{
				count++;
				j++;
			}
			break ;
		}
		if (str[j] == c)
			break ;
		count++;
		j++;
	}
	result = fill(str, count, index);
	return (result);
}

static char	**clear_arr(char **result, int j)
{
	while (j)
	{
		j--;
		free(result[j]);
	}
	free(result);
	return (NULL);
}

static int	string_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == c))
		i++;
	while (str[i])
	{
		count++;
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			while (str[i] != 34 && str[i] != 39)
				i++;
		}
		while (str[i] && (str[i] != c))
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static char	**process_string(char const *s, char c, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = allocation((char *)s, c, i);
			if (!result[j])
				return (clear_arr(result, j));
			i = handle_quote((char *)s, i, c);
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (string_count((char *)s, c) + 1));
	if (!result)
		return (NULL);
	result = process_string(s, c, result);
	return (result);
}
