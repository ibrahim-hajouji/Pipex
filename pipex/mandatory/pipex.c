/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:37:28 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/18 09:40:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			ft_free(paths, i);
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
		ft_exit();
	path = get_path(command[0], env);
	if (!path)
	{
		while (command[i])
			free(command[i++]);
		free(command);
		ft_exit();
	}
	if (execve(path, command, env) == -1)
		ft_exit();
}

void	child_process(char **av, char **env, int *fd)
{
	int	filein;

	filein = open(av[1], O_RDONLY);
	if (filein < 0)
		ft_exit();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	run(av[2], env);
}

void	parent_process(char **av, char **env, int *fd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout < 0)
		ft_exit();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	run(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_exit();
		pid = fork();
		if (pid < 0)
			ft_exit();
		if (!pid)
			child_process(av, env, fd);
		pid2 = fork();
		if (!pid2)
			parent_process(av, env, fd);
		close(fd[1]);
		close(fd[0]);
		wait(NULL);
		wait(NULL);
	}
	return (0);
}
