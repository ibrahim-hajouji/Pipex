/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:19:58 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/15 16:36:03 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			((char *)s)[i + 1] = '\0';
			return ((char *)s);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	size_t	result_len;

	i = 0;
	j = 0;
	result_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(result_len);
	if (!result)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			result[i++] = s1[j++];
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			result[i++] = s2[j++];
	}
	result[i] = '\0';
	return (result);
}

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
