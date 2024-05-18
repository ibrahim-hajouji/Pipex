/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:00 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/18 12:09:10 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fill_stdout(char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strncmp(line, limiter, ft__strlen(line) - 1) == 0))
			exit(0);
		write(fd, line, ft__strlen(line));
		free(line);
	}
}

void	here_doc(char *limiter, int ac)
{
	pid_t	pid;
	int		fd[2];

	if (ac < 6)
		ft_exit(2);
	if (pipe(fd) == -1)
		ft_exit(1);
	pid = fork();
	if (pid == -1)
		ft_exit(1);
	if (!pid)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		fill_stdout(limiter, fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	process(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit(1);
	pid = fork();
	if (pid == -1)
		ft_exit(1);
	if (!pid)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		run(cmd, env);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

void	execute(char **av, char **env, int fileout, int j)
{
	int		ac;
	int		forks_nbr;
	pid_t	pid2;

	ac = 0;
	while (av[ac])
		ac++;
	if (j == 1)
		forks_nbr = ac - 4;
	else
		forks_nbr = ac - 2;
	pid2 = fork();
	if (!pid2)
	{
		dup2(fileout, STDOUT_FILENO);
		run(av[ac - 2], env);
	}
	close(fileout);
	_wait(forks_nbr);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	filein;
	int	fileout;
	int	j;

	if (ac < 5)
		ft_exit(2);
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && (av[1][8] == '\0'))
	{
		j = 1;
		fileout = open_file(av[ac - 1], 0);
		dup2(fileout, STDOUT_FILENO);
		here_doc(av[2], ac);
		i = 3;
	}
	else
	{
		fileout = open_file(av[ac - 1], 1);
		filein = open_file(av[1], 2);
		dup_in(filein);
		i = 2;
	}
	while (i < ac - 2)
		process(av[i++], env);
	execute(av, env, fileout, j);
	while(1);
}
