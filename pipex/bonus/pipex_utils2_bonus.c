/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:38:29 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/18 09:53:43 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char *command, char **env)
{
	char	**paths;
	char	*part_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft__strjoin(paths[i], "/");
		path = ft__strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			ft__free(paths, i);
			return (path);
		}
		free(paths[i++]);
		free(path);
	}
	free(paths);
	return (NULL);
}

void	run(char *av, char **env)
{
	char	**command;
	char	*path;
	int		i;

	i = 0;
	command = ft_split(av, ' ');
	if (!command)
		ft_exit(1);
	path = get_path(command[0], env);
	if (!path)
	{
		while (command[i])
			free(command[i++]);
		free(command);
		ft_exit(1);
	}
	if (execve(path, command, env) == -1)
		ft_exit(1);
}

void	dup_in(int filein)
{
	dup2(filein, STDIN_FILENO);
	close(filein);
}

void	_wait(int i)
{
	while (i > 0)
	{
		wait(NULL);
		i--;
	}
}

int	open_file(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			ft_exit(1);
	}
	else if (mode == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			ft_exit(1);
	}
	else if (mode == 2)
	{
		fd = open(file, O_RDONLY, 0644);
		if (fd < 0)
			ft_exit(1);
	}
	return (fd);
}
